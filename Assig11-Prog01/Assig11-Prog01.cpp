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
