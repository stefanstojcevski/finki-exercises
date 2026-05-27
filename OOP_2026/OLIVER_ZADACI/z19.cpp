#include<iostream>
#include<cstring>
using namespace std;
class Student{
private:
    char name[20];
    char lastName[20];
    int indexNumber;
    int ocenki[5];
public:
    Student(){
        strcpy(this->name,"");
        strcpy(this->lastName,"");
        this->indexNumber=0;
        for(int i=0;i<5;i++){
            this->ocenki[i]=0;
        }
    }
    Student(char name[20],char lastName[20],int indexNumber,int ocenki[5]){
        strcpy(this->name,name);
        strcpy(this->lastName,lastName);
        this->indexNumber=indexNumber;
        for(int i=0;i<5;i++){
            this->ocenki[i]=ocenki[i];
        }
    }
    ~Student(){
    }
    float getProsek(){
        float zbir=0;
        for(int i=0;i<5;i++){
            zbir=zbir+ocenki[i];
        }
        return zbir/5.0;
    }
    void display(){
        float zbir=0;
        for(int i=0;i<5;i++){
            zbir=zbir+ocenki[i];
        }
        cout<<name<<" "<<lastName<<" "<<indexNumber<<zbir/5.0<<endl;
    }

};
void bestStudents(Student *student,int n){
    Student temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(student[j].getProsek()>student[j+1].getProsek()){
                temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        student[i].display();
    }
}
int main() {
    int n;
    cin>>n;
    Student students[n];
    for (int i=0;i<n;i++) {
        char name[20];
        char lastName[20];
        int indexNumber;
        int ocenki[5];
        cin>>name;
        cin>>lastName;
        cin>>indexNumber;
        for (int j=0;j<5;j++) {
            cin>>ocenki[j];

        }
        Student s(name,lastName,indexNumber,ocenki);
        students[i]=s;

    }
    bestStudents(students,n);
    return 0;

}