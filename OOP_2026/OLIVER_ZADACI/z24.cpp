#include <iostream>
#include <cstring>
using namespace std;
class SpaceObject {
private:
    char name[100];
    char type[100];
    int distanceFromEarth;
public:
     SpaceObject() {
        strcpy(this->name,"");
        strcpy(this->type,"");
         this->distanceFromEarth=0;
    }
    SpaceObject(char name[100],char type[100],int distanceFromEarth) {
         strcpy(this->name,name);
         strcpy(this->type,type);
         this->distanceFromEarth=distanceFromEarth;
     }
    ~SpaceObject() {

     }
    void print() {
         cout<<name<<" ("<<type<<") - "<<"distance: "<<distanceFromEarth<<" light years away from Earth"<<endl;
     }
    int getDistance() {
         return distanceFromEarth;
     }
};
class Alien {
private:
    char bname[100];
    int age;
    char homePlanet[100];
    SpaceObject spaceObjects[50];
    int n;
public:
    Alien() {
        strcpy(this->bname,"");
        this->age=0;
        strcpy(this->homePlanet,"");
        this->n=0;
    }
    Alien(char bname[100], int age, char homePlanet[100], SpaceObject objects[], int n) {
        strcpy(this->bname,bname);
        this->age=age;
        strcpy(this->homePlanet,homePlanet);
        this->n=n;
        for(int i=0;i<n;i++){
            spaceObjects[i] = objects[i];
        }
    }
    ~Alien() {

    }
    SpaceObject getObjectClosestToEarth() {
        int min = 0;

        for(int i = 1; i < n; i++){
            if(spaceObjects[i].getDistance() < spaceObjects[min].getDistance()){
                min = i;
            }
        }

        return spaceObjects[min];
    }

    void print() {
       cout<<"name: "<<bname;
       cout<<"age: "<<age;
       cout<<"home planet:"<<homePlanet;
       cout<<"Favourite space object closest to earth: " <<endl;
        getObjectClosestToEarth().print();
    }


    };





    int main() {

        char alienName[100];
        int age;
        char homePlanet[100];

        int n;
        cin >> n;

        SpaceObject objects[50];

        for(int i = 0; i < n; i++){
            char name[100];
            char type[100];
            int distance;

            cin >> name;
            cin >> type;
            cin >> distance;

            objects[i] = SpaceObject(name, type, distance);
        }

        cin >> alienName;
        cin >> age;
        cin >> homePlanet;

        Alien a(alienName, age, homePlanet, objects, n);

        a.print();

        return 0;
    }

