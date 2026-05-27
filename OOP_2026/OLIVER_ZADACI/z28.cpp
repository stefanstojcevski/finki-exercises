#include <iostream>
#include <cstring>
using namespace std;
class Achievement {
private:
    char name[50];
    char description[50];
    static int totalUserAchievements;
public:
    Achievement() {
        strcpy(this->name," ");
        strcpy(this->description," ");
    }
    Achievement(char name[50], char description[50]) {
        strcpy(this->name,name);
        strcpy(this->description,description);
    }
    Achievement(const Achievement &a) {
        strcpy(this->name,a.name);
        strcpy(this->description,a.description);
    }
    ~Achievement() {

    }
    void print() {
        cout<<name<<endl;
        cout<<description<<endl;
    }

    friend class UserProfile;
    static void incrementTotalUserAchievements() {
        totalUserAchievements++;


    }
    friend class UserProfile;
};
class UserProfile {
private:
    char name[50];
    Achievement achievements[50];
    int n;
public:
    UserProfile() {
        strcpy(this->name," ");
        this->n=0;
    }
    UserProfile( char name[50]) {
        strcpy(this->name,name);
        this->n=0;
    }
    UserProfile( const UserProfile &u) {
        strcpy(this->name,u.name);
        this->n=u.n;
        for (int i=0;i<u.n;i++) {
            this->achievements[i]=u.achievements[i];
        }
    }
    void print() {
        cout<<name<<endl;
        for(int i = 0; i < n; i++) {
            achievements[i].print();
        }
    }
    void addAchievement(Achievement a) {
        if (n>=50) {
            return;
        }
        achievements[n] = a;
        n++;

        Achievement::incrementTotalUserAchievements();

    }
    friend void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m);
};
void showAchievementsProgress(UserProfile profiles[], int n, Achievement achievements[], int m) {

}
int Achievement::totalUserAchievements = 0;
int main() {
        char testcase[100];
        cin.getline(testcase, 100);

        int n;
        cin >> n;
        cin.ignore();

        char ignore[100];
        cin.getline(ignore, 100);
        UserProfile users[100];
        for (int i = 0; i < n; ++i) {
            char name[100];
            cin >> name;
            users[i] = UserProfile(name);
        }

        int m;
        cin >> m;
        cin.ignore();

        cin.getline(ignore, 100);
        Achievement achievements[100];
        for (int i = 0; i < m; ++i) {
            char name[100], description[100];
            cin.getline(name, 100);
            cin.getline(description, 100);
            achievements[i] = Achievement(name, description);
        }

        int k;
        cin >> k;
        cin.ignore();

        cin.getline(ignore, 100);
        for (int i = 0; i < k; ++i) {
            int numUser, numAchievement;
            cin >> numUser >> numAchievement;
            numUser -= 1;
            numAchievement -= 1;
            users[numUser].addAchievement(achievements[numAchievement]);
        }

        if (testcase[8] == 'A') {  // Testing Achievement methods.
            for (int i = 0; i < m; ++i) {
                achievements[i].print();
            }
            Achievement::incrementTotalUserAchievements();
        } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
            for (int i = 0; i < n; ++i) {
                users[i].print();
            }
        } else {  // Testing showAchievementsProgress function.
            showAchievementsProgress(users, n, achievements, m);
        }

        return 0;
    }

