//Huan Chen Assignment11-Program03
#include<iostream>
#include<iomanip>
#include<cctype>
using namespace std;

enum Employees {hourly, salaried};

struct worker{
    enum Employees e;
    double total;
    union {
        struct {
            int hours;
            double payRate;
        };
        struct {
            double salary;
            double bonus;
        };
        
    };
};

void getHourly(worker &h){
    h.e = hourly;
    cout<<"Enter the number of hours worked: ";
    cin>>h.hours;
    if(h.hours < 0){
        cout<<"Hours worked must be equal or greater than 0."<<" Re-enter: ";
        cin>>h.hours;
    }
    cout<<"Enter the hourly pay rate: ";
    cin>>h.payRate;
    if(h.payRate < 0){
        cout<<"Pay rate must be equal or greater than 0."<<" Re-enter: ";
        cin>>h.payRate;
    }
    h.total=h.hours*h.payRate;
}

void getSalary(worker &s){
    s.e = salaried;
    cout<<"Enter the salary amount: ";
    cin>>s.salary;
    if(s.salary < 0){
        cout<<"Salary must be equal or greater than 0."<<" Re-enter: ";
        cin>>s.salary;
    }
    cout<<"Enter the bonus amount: ";
    cin>>s.bonus;
    if(s.bonus < 0){
        cout<<"Bonus must be equal or greater than 0."<<" Re-enter: ";
        cin>>s.bonus;
    }
    s.total=s.salary+s.bonus;
}

void printWorker(const worker worker){
    if(worker.e == hourly){
        cout<<"Hourly Worker"<<endl;
        cout<<"Hours: "<<worker.hours<<endl;
        cout<<"Rate: $"<<worker.payRate<<endl;
        cout<<"-----------"<<endl;
        cout<<"Gross Pay: $"<<worker.total<<endl;
    }else{
        cout<<"Salaried Worker"<<endl;
            cout<<"Salary: $"<<setprecision(2)<<fixed<<worker.salary<<endl;
            cout<<"Bonus: $"<<setprecision(2)<<fixed<<worker.bonus<<endl;
            cout<<"-----------"<<endl;
            cout<<"Gross Pay: $"<<setprecision(2)<<fixed<<worker.total<<endl;
    }
}

int main(){
    char userInput, choice;
    cout<<"(H)ourly or (S)alaried?";
    cin>>userInput;
    if(userInput != 's' && userInput != 'h' && userInput != 'H' && userInput != 'S'){
        cout<<"Invalid. Please enter either s/S or h/H"<<endl;
        cin>>userInput;
    }
    choice = toupper(userInput);
    worker worker1;
    switch(choice){
        case 'H':
            getHourly(worker1);
            printWorker(worker1);
            break;
        case 'S':
            getSalary(worker1);
            printWorker(worker1);
            break;
    }
}


