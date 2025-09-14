#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class and vector practice
class Review {
    public:
        void SetRatingAndComment(int revRating, string revComment) {
            rating = revRating;
            comment = revComment;
        }
        int GetRating() const {
            return rating;
        }
        string GetComment() const {
            return comment;
        }

    private:
        int rating = -1; // Default to -1 to indicate no rating set
        string comment = "No comment"; // Default comment
};

int main() {
    vector<Review> reviewList; // Vector to store reviews
    Review currReview; // Current review object
    int currRating;
    string currComment;
    unsigned int i; // Loop counter

    cout << "Type rating + comments. To end: -1" << endl;
    cin >> currRating;
    cin.ignore(); // Ignore newline character after integer input
    while (currRating >= 0) {
        getline(cin, currComment); // Read the entire line for comment
        currReview.SetRatingAndComment(currRating, currComment); // Set rating and comment
        reviewList.push_back(currReview); // Add current review to the list

        cout << "Type rating + comments. To end: -1" << endl;
        cin >> currRating;
        cin.ignore(); // Ignore newline character after integer input
    }

    // output all comments for given rating
    cout << endl << "Type rating to see comments. To end: -1" << endl;
    cin >> currRating;
    while (currRating != -1) {
        cout << "Comments with rating " << currRating << ":" << endl;
        for (i = 0; i < reviewList.size(); i++) {
            currReview = reviewList.at(i);
            if (currRating == currReview.GetRating()) {
                cout << currReview.GetComment() << endl;
            }
        }
        cout << endl << "Type rating to see comments. To end: -1" << endl;
        cin >> currRating;
    }
    return 0;
}