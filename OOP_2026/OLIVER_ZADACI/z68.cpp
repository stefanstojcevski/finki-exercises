#include <iostream>
#include<cstring>
using namespace std;
class Task {
protected:
    char id[5];
public:
    Task() {
        strcpy(this->id,"");
    }

    Task(char id[5]) {
        strcpy(this->id,id);
    }

    Task(const Task &t) {
        strcpy(this->id,t.id);
    }
    virtual int getOrder()=0;
    virtual void print()=0;
    char * getId(){return id;}
};
class TimedTask:public Task {
protected:
    int vreme;
public:
    TimedTask() {
        this->vreme=0;
    }
    TimedTask( char id[5],int vreme):Task(id) {
        this->vreme=vreme;
    }
    TimedTask(const TimedTask &i):Task(i) {
        this->vreme=i.vreme;
    }


    int getOrder(){return vreme;}
};

class PriorityTask:public Task{
protected:
    int prioritet;
public:
    PriorityTask() {
        this->prioritet=0;
    }
    PriorityTask( char id[5],int prioritet):Task(id) {
        this->prioritet=prioritet;
    }
    PriorityTask(const PriorityTask &i):Task(i) {
        this->prioritet=i.prioritet;
    }
    int getOrder(){return prioritet;}

};

bool operator==(Task *t1,Task &t2){
    return (t1->getOrder()==t2.getOrder()&&(strcmp(t1->getId(),t2.getId())==0) );
}

void scheduleTimedTasks(Task ** tasks, int n, int t){
    TimedTask *tt=NULL;
    for(int i =0;i<t;i++){
        for(int j = 0;j<n;j++){
            tt=NULL;
            tt = dynamic_cast<TimedTask*>(tasks[j]);
            if(tt!=NULL)
                if(tasks[j]->getOrder()==i){
                    tasks[j]->print();
                    break;
                }
        }
    }
}




int main() {
    int testCase;
    int n;
    cin>>testCase;

    if (testCase==0){
        cin>>n;
        Task ** tasks;
        tasks = new Task * [n];
        for (int i=0;i<n;i++){
            char id [5];
            int timeOrPriority;
            int type; //0 za timed, 1 za priority
            cin >> type >>id >> timeOrPriority;
            if (type==0)
                tasks[i] = new TimedTask(id,timeOrPriority);
            else
                tasks[i] = new PriorityTask(id,timeOrPriority);
            //tasks[i]->print();
        }

        cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
        schedulePriorityTasks(tasks,n,10);

    }
    else if (testCase==1) {
        cin>>n;
        Task ** tasks;
        tasks = new Task * [n];
        for (int i=0;i<n;i++){
            char id [5];
            int timeOrPriority;
            int type; //0 za timed, 1 za priority
            cin >> type >>id >> timeOrPriority;
            if (type==0)
                tasks[i] = new TimedTask(id,timeOrPriority);
            else
                tasks[i] = new PriorityTask(id,timeOrPriority);
            //tasks[i]->print();
        }


        cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
        scheduleTimedTasks(tasks,n,50);
    }
    else {
        TimedTask * tt1 = new TimedTask("11",10);
        TimedTask * tt2 = new TimedTask("11",11);
        TimedTask * tt3 = new TimedTask("11",11);
        PriorityTask * pp1 = new PriorityTask("aa",10);
        PriorityTask * pp2 = new PriorityTask("11",10);

        cout << (tt1==(*tt2))<<endl;
        cout << (tt2==(*tt3))<<endl;
        cout << (pp1==(*pp2))<<endl;
        cout << (pp2==(*tt1))<<endl;
    }

    return 0;
}