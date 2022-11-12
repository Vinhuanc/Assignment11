//Huan Chen Assignment11-Program02
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct player{
    string name;
    int number;
    int points;
};

player players[11];

void getPlayers(player &p){
    for(int i=0; i<=11; i++){
        cout<<"Player"<<endl;
        cout<<"--------"<<endl;
        cout<<"Player's name: ";
        cin>>players[i].name;
        cout<<"Player's number: ";
        cin>>players[i].number;
        if(players[i].number<0){
            cout<<"Error. Player's number cannot be less than 0.  Re-enter:";
            cin>>players[i].number;
        }
        cout<<"Points scored: ";
        cin>>players[i].points;
        if(players[i].points<0){
            cout<<"Error. Player's points cannot be less than 0.  Re-enter:";
            cin>>players[i].points;
        }
    }
}

void displayTable(){
    int total=0, high=0, highNum;
    string highName;
    cout<<"NAME"<<"\t\t"<<"NUMBER"<<"\t"<<"PTS"<<"\t"<<"SCRD"<<endl;
    high=players[0].points;
    highName=players[0].name;
    highNum=players[0].number;
    for(int i=0; i<=11; i++){
        cout<<players[i].name<<"\t\t"<<players[i].number<<"\t\t"<<players[i].points<<endl;
        total += players[i].points;
        if(high<players[i].points){
            high =players[i].points;
            highName =players[i].name;
            highNum = players[i].number;
        }
    }
    cout<<"TOTAL POINTS: "<<"\t"<<total<<endl;
    cout<<"The player who scored the most points is: "<< highName<<" #"<< highNum<<endl;
}


int main(){
    player s;
    getPlayers(s);
    displayTable();
}
//Program #2
//Write a program that stores information about 12 players in an array of structures. The structure (player) will contain 3 member fields: name, number, and points. When your program runs, it should call a function that will prompt the user to enter data for each of the fields for each of the 12 players. The function should take a reference parameter. Your program will then display a table of all of the players, and total points for the team. The number and name of the player who earned the most points should also be displayed.
//Sample Outputs: PLAYER
//---------
//Player's name: Ella Player's number: 23 Points scored: 53 PLAYER
//---------
//Player's name: John Player's number: 13 Points scored: 32 PLAYER
//---------
//Player's name: James Player's number: 42 Points scored: 13 PLAYER
//---------
//Player's name: Frankie Player's number: 82 Points scored: 14 PLAYER
//---------
//Player's name: Lindsey Player's number: 84 Points scored: 24
//PLAYER
//---------
//Player's name: Gabriel Player's number: 46 Points scored: 24 PLAYER
//---------
//Player's name: Ruth Player's number: 62 Points scored: 34 PLAYER
//---------
//Player's name: Fred Player's number: 73 Points scored: 9 PLAYER
//---------
//Player's name: Molly Player's number: 47 Points scored: 32 PLAYER
//---------
//Player's name: Nick Player's number: 99 Points scored: 11 PLAYER
//---------
//Player's name: Karen Player's number: 96 Points scored: 23 PLAYER
//---------
//Player's name: Terry Player's number: 44 Points scored: 6
//NAME
//Ella
//John
//James
//Frankie
//Lindsey
//Gabriel
//Ruth
//Fred
//Molly
//Nick
//Karen
//Terry
//NUMBER PTS SCRD
//    23 53
//    13 32
//    42 13
//    82 14
//    84 24
//    46 24
//    62 34
//    73 9
//    47 32
//    99 11
//    96 23
//    44 6
//TOTAL POINTS: 275
//The player who scored the most points is: Ella #23 Press any key to continue . . .
