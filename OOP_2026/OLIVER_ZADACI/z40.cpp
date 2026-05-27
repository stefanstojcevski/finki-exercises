#include<iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char *name;
    int age;
    char *major;

public:
    Student() {
        strcpy(this->name, "");
        this->age = 0;
        strcpy(this->major, "");
    }

    Student(char *name, int age, char *major) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
    }

    Student(const Student &s) {
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
        this->age = s.age;
        this->major = new char[strlen(s.major) + 1];
        strcpy(this->major, s.major);
    }

    Student &operator=(const Student &s) {
        if (this != &s) {
            delete [] name;
            delete [] major;
            this->name = new char[strlen(s.name) + 1];
            strcpy(this->name, s.name);
            this->age = s.age;
            this->major = new char[strlen(s.major) + 1];
            strcpy(this->major, s.major);
        }
        return *this;
    }

    ~Student() {
        delete [] name;
        delete [] major;
    }

    friend class Classroom;
};


class Classroom {
private:
    Student *students;
    int numStudents;
    int capacity;

public:
    Classroom() {
        this->numStudents = 0;
        this->students = nullptr;
        this->capacity = 0;
    }

    Classroom(Student *students, int numStudents, int capacity) {
        this->numStudents = numStudents;
        this->students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            this->students[i] = students[i];
        }
        this->capacity = capacity;
    }

    Classroom(const Classroom &c) {
        this->numStudents = c.numStudents;
        this->students = new Student[c.numStudents];
        for (int i = 0; i < c.numStudents; i++) {
            this->students[i] = c.students[i];
        }
        this->capacity = c.capacity;
    }

    Classroom &operator=(const Classroom &c) {
        if (this != &c) {
            delete [] students;
            this->numStudents = c.numStudents;
            this->students = new Student[c.numStudents];
            for (int i = 0; i < c.numStudents; i++) {
                this->students[i] = c.students[i];
            }
            this->capacity = c.capacity;
        }
        return *this;
    }


    ~Classroom() {
        delete [] students;
    }


    void add(Student s) {
        Student *tmp = new Student[numStudents + 1];
        for (int i=0;i<numStudents;i++) {
            tmp[i]=students[i];
        }
        tmp[numStudents]=s;
        delete [] students;
        students=tmp;
        numStudents++;
    }
    void remove(char *name) {
        for (int i=0;i<numStudents;i++) {
            if (strcmp(name,students[i].name)==0) {
                for (int j = i; j < numStudents - 1; j++) {
                    students[j] = students[j + 1];
                }
                numStudents--;
                i--;


            }
        }
    }

    double findMedianAge() {
        Student tmp;
        for (int i = 0; i < numStudents - 1; i++) {
            for (int j = i + 1; j < numStudents; j++) {
                if (students[i].age > students[j].age) {
                    tmp = students[i];
                    students[i] = students[j];
                    students[j] = tmp;
                }
            }
        }
        if (numStudents % 2 == 0) {
            return (students[numStudents / 2 - 1].age + students[numStudents / 2].age) / 2.0;
        } else {
            return students[numStudents / 2].age;
        }
    }
    void printStudents() {
        for (int i = 0; i < numStudents; i++) {
            cout << students[i].name << " " << students[i].age << " " << students[i].major << endl;
        }
    }
};


int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i * numStudents + j] = student;
        }
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }


    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = findMedianAge(classrooms[targetClassroom]);
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout << "After removing the elements:" << endl; /// Added
    // Testing remove method
    //The program was correctly solve by Professor Oliver Nikolajeivc
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }

    return 0;
}
