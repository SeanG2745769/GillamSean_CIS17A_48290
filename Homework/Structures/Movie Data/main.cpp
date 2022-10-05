#include <iostream>
#include <string>

using namespace std;

struct MovieData
{
    string title;
    string director;
    int year;
    int runTime;
};

void display(struct MovieData m[], int size);

int main(){
    
    int numMovies;
    string tHold;
    string dHold;
    
	cout << "This program reviews structures\n";
	cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the "
	    "Running Time in (minutes).\n";
	cin >> numMovies;
	cin.ignore();
	
	struct MovieData movie[numMovies]; //This will be initialized at plus 1 because user enters plus 1 value for an array
	
	int i;
	for(i = 0; i < (numMovies); i++)
	{
	    getline(cin, tHold);
	    getline(cin, dHold);
	    cin >> movie[i].year;
	    cin >> movie[i].runTime;
	    cin.ignore();
	    
	    movie[i].title = tHold;
	    movie[i].director = dHold;
	}
	
	display(movie, numMovies);
	
	return 0;
}

void display(struct MovieData m[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout <<"\nTitle:     "<< m[i].title << endl;
        cout <<"Director:  "<< m[i].director << endl;
        cout <<"Year:      "<< m[i].year << endl;
        cout <<"Length:    "<< m[i].runTime << endl;
    }
}

