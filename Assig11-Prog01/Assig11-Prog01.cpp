//Huan Chen Assignment11-Program01
#include<iostream>
#include<string>
using namespace std;

struct movieData{
    string title;
    string director;
    int year;
    int runtime;
};

void displayMovie(const movieData &m){
    cout<<"Title"<<"\t\t"<<" : "<<m.title<<endl;
    cout<<"Director"<<"\t"<<" : "<<m.director<<endl;
    cout<<"Released "<<"\t"<<" : "<<m.year<<endl;
    cout<<"Running time "<<": "<<m.runtime<<" minutes"<<endl;
    cout<<"                       "<<endl;
}

int main(){
    movieData movie1 ={"Pretty Little Liars", "Arthur Anderson", 2014, 41};
    movieData movie2;
    movie2.title="Little Alvin and the Mini-Munks";
    movie2.director="Jerry Rees";
    movie2.year=2003;
    movie2.runtime=80;
    displayMovie(movie1);
    displayMovie(movie2);
}
//Program #1
//Write a program that uses a structure to pass around Movie Data information. Your program will have a function that prints all of the information about the structure, which will be called from your main function. Your main function will create two Movie Data variables, initializing them before calling the display function (one call per variable). One of your variables will be initialized using an initialization list, while the other will be initialized member by member. Please name the fields of your structure: title, director, year, and runtime. Please name your structure movieData, and the name of your display function displayMovie. Pass your structure to your function by constant reference parameter. You may use 2 movies of your choice to fill the data for the variables.
//Sample Outputs:
//Title
//Director
//Released
//Running Time: 88 minutes
//: War of the Worlds : Byron Haskin
//: 1953
//Title
//Director
//Released
//Running Time: 118 minutes
//Press any key to continue . . .
