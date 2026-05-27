#include <iostream>
#include <cstring>
using namespace std;
class Game {
protected:
    char title[50];
public:
    Game() {
       strcpy( this->title,"");
    }
    Game( char title[50]) {
        strcpy( this->title,title);
    }
    Game(const Game &g) {
        strcpy( this->title,g.title);
    }
    virtual void displayInfo() {
        cout<<"Game: "<<title<<endl;
    }
    virtual int complexity() {
        return 0;
    }
};
class BoardGame:virtual public Game {
protected:
    int maxPlayers;
public:
    BoardGame() {
        this->maxPlayers=0;
    }
    BoardGame( char title[50],int maxPlayers):Game(title) {
        this->maxPlayers=maxPlayers;
    }
    BoardGame( const BoardGame &b):Game(b) {
        this->maxPlayers=b.maxPlayers;
    }
    int complexity() {
        if (maxPlayers>6) {
            return 10;
        }
        else if (maxPlayers>3 && maxPlayers<=6) {
            return 5;
        }
        else if (maxPlayers<3) {
            return 3;
        }
    }
     void displayInfo() {
        cout<<"Game: "<<title<<endl;
        cout<<"MaxPlayers: "<<maxPlayers<<endl;
        cout<<"Complexity: "<<complexity()<<endl;
    }
};
class CardGame:virtual public Game {
protected:
int numCards;

public:
    CardGame() {
        this->numCards=0;
    }
    CardGame( char title[50],int numCards):Game(title) {
        this->numCards=numCards;
    }
    CardGame( const CardGame &b):Game(b) {
        this->numCards=b.numCards;
    }
    int complexity() {
        if (numCards>20) {
            return 10;
        }
        else if (numCards>10 && numCards<=20) {
            return 5;
        }
        else if (numCards<10) {
            return 3;
        }
    }
    void displayInfo() {
        cout<<"Game: "<<title<<endl;
        cout<<"NumCards: "<<numCards<<endl;
        cout<<"Complexity: "<<complexity()<<endl;
    }
};
class BoardCardGame:public BoardGame, public CardGame {
protected:
public:
    BoardCardGame(char title[50],int maxPlayers,int numCards):Game(title),BoardGame(title,maxPlayers),CardGame(title, numCards){

    }
    int complexity(){
        return (CardGame::complexity()+BoardGame::complexity())/2;
    }
    void displayInfo(){
        cout<<"Game: "<<title<<endl;
        cout<<"Complexity: "<<complexity()<<endl;
    }
};
Game* mostComplexCardGame(Game **game,int n) {
    int max=0;
    for (int i=0;i<n;i++) {
        CardGame *cg=dynamic_cast<CardGame *>(game[i]);
            if (cg) {
                if (game[i]->complexity()>game[max]->complexity()) {
                    max=i;
                }
            }
        }
    return game[max];
    }

int main() {
    char title[50];
    int maxPlayers;
    int numCards;
    int n;
    int choice;

    cin>>choice;
    if(choice==1)
    {
        cin>>title;
        BoardCardGame boardCardGame(title, 8, 15);
        boardCardGame.displayInfo();
    }
    else {

        cin >> n;

        Game **g = new Game *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> title >> maxPlayers;

                g[i] = new BoardGame(title, maxPlayers);
            } else {
                cin >> title >> numCards;

                g[i] = new CardGame(title, numCards);
            }

        }

        mostComplexCardGame(g,n)->displayInfo();

    }


    return 0;
}