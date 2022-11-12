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

//Program #3
//Write a program that calculates pay for either an hourly paid worker, or a salaried worker. Hourly workers will have a pay rate and hours worked, while salaried worker will have a salary and bonus. The program should create a structure that works for both of these types of workers.
//The program should ask the user what type of worker they have information for, followed by questions related to the specific type of worker. You will create a function that will handle getting the input for the specific type of worker, using a reference parameter (getHourly & getSalaried). You will then call a print function that will use the information in the structure to print a report for that worker (call the function printWorker and use a const reference parameter).
//The structure definition name should contain the word “worker”. It will contain an enum, a double (for the gross pay), and a union of two sub-structures. The sub-structures will each have 2 fields, relating to the hourly and salaried data points. One sub-structure will be the hourly data; the other will be the salaried data.
//I highly recommend the idea of nesting the structs and unions in a single definition. You can think of the outer struct as containing information that is common to all variations of the full structure, while also having a union for the features that are unique to each variation (those features possibly needing to be groups themselves into structures if the variation has more than one unique feature). The question you then have for yourself is how you tell which part of the union to use when interacting with the structure variable – the answer to that lies with the enum datatype, where you can define a structure member (in the outer structure) that is a datatype of an enum with values for each of the variations. You then set which variation your variable represents in the enum member, and utilize that variation’s fields in the union. All while being able to reference these different variations with a single structure name.
//Sample Outputs:
//(H)ourly or (S)alaried? S
//Enter the salary amount: 23058
//Enter the bonus amount: 3802 Salaried Worker
//Salary: $23058.00
//Bonus: $3802.00
//----------
//Gross Pay: $26860.00
//Press any key to continue . . . ==================================== (H)ourly or (S)alaried? H
//Enter the number of hours worked: 39 Enter the hourly pay rate: 14.83 Hourly Worker
//Hours: 39
//Rate: $14.83
//----------
//Gross Pay: $578.37
