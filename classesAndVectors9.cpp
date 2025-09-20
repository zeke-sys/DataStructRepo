#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Song sets duration and name of song
// class album sets name, inputs songs, prints name, and prints songs longer than given duration

class Song {
    public:
        void SetDurationAndName(int songDuration, string songName) {
            duration = songDuration;
            name = songName;
        }
        void PrintSong() const {
            cout << "Song: " << name << ", Duration: " << duration << " seconds" << endl;
        }
        int GetDuration() const {
            return duration;
        }
        string GetName() const {
            return name;
        }

    private:
        int duration; // Duration in seconds
        string name; // Name of the song
};

class Album {
    public:
        void SetName(string albumName) {
            name = albumName;
        }
        void InputSongs();
        void PrintName() const {
            cout << "Album: " << name << endl;
        }
        void PrintSongsLongerThan(int songDuration) const;

    private:
        string name; // Name of the album
        vector<Song> albumSongs; // Vector to store songs
};

void Album::InputSongs() {
    Song currSong; // Current song object
    int currDuration;
    string currName;
    unsigned int i; // Loop counter

    cout << "Type song duration in seconds + name. To end: -1" << endl;
    cin >> currDuration;
    cin.ignore(); // Ignore newline character after integer input
    while (currDuration >= 0) {
        getline(cin, currName); // Read the entire line for song name
        currSong.SetDurationAndName(currDuration, currName); // Set duration and name
        albumSongs.push_back(currSong); // Add current song to the list

        cout << "Type song duration in seconds + name. To end: -1" << endl;
        cin >> currDuration;
        cin.ignore(); // Ignore newline character after integer input
    }
}

void Album::PrintSongsLongerThan(int songDuration) const {
    unsigned int i; // Loop counter
    cout << "Songs longer than " << songDuration << " seconds:" << endl;
    for (i = 0; i < albumSongs.size(); i++) {
        if (albumSongs.at(i).GetDuration() > songDuration) {
            albumSongs.at(i).PrintSong(); // Print details of the song
        }
    }
}

int main() {
    Album myAlbum; // Album object
    string albumName;
    int durationThreshold;

    cout << "Type album name:" << endl;
    getline(cin, albumName); // Read the entire line for album name
    myAlbum.SetName(albumName); // Set album name

    myAlbum.InputSongs(); // Input songs

    myAlbum.PrintName(); // Print album name

    cout << "Type duration threshold in seconds to see songs longer than that:" << endl;
    cin >> durationThreshold;
    myAlbum.PrintSongsLongerThan(durationThreshold); // Print songs longer than the given duration

    return 0;
}
