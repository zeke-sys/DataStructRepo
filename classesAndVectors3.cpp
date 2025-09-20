#include <iostream>
#include <string>
#include <vector>

using namespace std;

//code assigns title and duration to currMovie
//and stores currMovie in myMovies
//input first title value and duration value

class Movie {
    public:
        void SetTitleAndDuration(string movTitle, int movDuration) {
            title = movTitle;
            duration = movDuration;
        }
        void PrintInfo() const {
            cout << "Title: " << title << ", Duration: " << duration << " minutes" << endl;
        }
        string GetTitle() const {
            return title;
        }
        int GetDuration() const {
            return duration;
        }

    private:
        string title = "No title"; // Default title
        int duration = 0; // Default duration
};

int main() {
    vector<Movie> myMovies; // Vector to store movies
    Movie currMovie; // Current movie object
    string currTitle;
    int currDuration;
    unsigned int i; // Loop counter

    cout << "Type title and duration (in minutes). To end: 'end' 0" << endl;
    cin >> ws; // Clear leading whitespace
    getline(cin, currTitle);
    cin >> currDuration;
    while (currTitle != "end" && currDuration != 0) {
        currMovie.SetTitleAndDuration(currTitle, currDuration); // Set title and duration
        myMovies.push_back(currMovie); // Add current movie to the list

        cout << "Type title and duration (in minutes). To end: 'end' 0" << endl;
        cin >> ws; // Clear leading whitespace
        getline(cin, currTitle);
        cin >> currDuration;
    }

    // Output all movies
    cout << endl << "Movies entered:" << endl;
    for (i = 0; i < myMovies.size(); i++) {
        currMovie = myMovies.at(i);
        currMovie.PrintInfo();
    }

    return 0;
}