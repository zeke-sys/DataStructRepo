#include <iostream>
#include <string>
#include <vector>

using namespace std;

// code reads a list of song durations and song names from input
// sets duration and name of currSong for each line of input
// then adds currSong to playList
// input first duration value and name value

class Song {
    public:
        void SetDurationAndName(int songDuration, string songName) {
            duration = songDuration;
            name = songName;
        }
        void PrintInfo() const {
            cout << "Song: " << name << ", Duration: " << duration << " seconds" << endl;
        }
        string GetName() const {
            return name;
        }
        int GetDuration() const {
            return duration;
        }

    private:
        string name = "No name"; // Default name
        int duration = 0; // Default duration
};

int main() {
    vector<Song> playList; // Vector to store songs
    Song currSong; // Current song object
    string currName;
    int currDuration;
    unsigned int i; // Loop counter

    cout << "Type duration (in seconds) and name. To end: 0 'end'" << endl;
    cin >> currDuration;
    cin.ignore(); // Ignore newline character after integer input
    getline(cin, currName);
    while (currDuration != 0 && currName != "end") {
        currSong.SetDurationAndName(currDuration, currName); // Set duration and name
        playList.push_back(currSong); // Add current song to the list

        cout << "Type duration (in seconds) and name. To end: 0 'end'" << endl;
        cin >> currDuration;
        cin.ignore(); // Ignore newline character after integer input
        getline(cin, currName);
    }

    // Output all songs
    cout << endl << "Songs in playlist:" << endl;
    for (i = 0; i < playList.size(); i++) {
        currSong = playList.at(i);
        currSong.PrintInfo();
    }

    return 0;
}

