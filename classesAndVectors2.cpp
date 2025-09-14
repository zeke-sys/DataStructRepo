#include <iostream>
#include <string>
using namespace std;

// finding and searching in a vector
class Vector10 {
    public:
        Vector10();
        bool search(int val);
    
    private:
        int arr[10];
        int cursor;
};

Vector10::Vector10() { // constructor
    cursor = 0;
    for (int i = 0; i < 10; i++) { // fill array with values 0-9
        arr[i] = cursor;
        cursor++;
    }
} 

bool Vector10::search(int val) {
    for (int i = 0; i < 10; i++) {
        if (arr[i] == val) {
            return true; // found
        }
    }
    return false; // not found
}

int main() {
    Vector10 v; // create object
    int val;
    cout << "Type a number to search for (0-9). To end: -1" << endl;
    cin >> val;
    while (val != -1) {
        if (v.search(val)) {
            cout << "Found!" << endl;
        } else {
            cout << "Not found!" << endl;
        }
        cout << "Type a number to search for (0-9). To end: -1" << endl;
        cin >> val;
    }
    return 0;
}
