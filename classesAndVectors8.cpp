#include <iostream>
#include <vector>
using namespace std;

// smallCities class
// InputTowns()
// if row number is not equal to -99, use Town object's ReadDetails() function to read town details
// and append to Town object to vector townList

class Town {
    public:
        void ReadDetails();
        void PrintDetails() const;
    private:
        int population;
        string name;
};

void Town::ReadDetails() {
    cin >> population;
    cin.ignore(); // Ignore newline character after integer input
    getline(cin, name); // Read the entire line for town name
}

void Town::PrintDetails() const {
    cout << "Town Name: " << name << ", Population: " << population << endl;
}

class SmallCities {
    public:
        void InputTowns();
        void PrintAllTowns() const;
    private:
        vector<Town> townList; // Vector to store towns
};

void SmallCities::InputTowns() {
    Town currTown; // Current town object
    int rowNumber;
    unsigned int i; // Loop counter

    cout << "Type row number. To end: -99" << endl;
    cin >> rowNumber;
    while (rowNumber != -99) {
        currTown.ReadDetails(); // Read town details
        townList.push_back(currTown); // Add current town to the list

        cout << "Type row number. To end: -99" << endl;
        cin >> rowNumber;
    }
}

void SmallCities::PrintAllTowns() const {
    unsigned int i; // Loop counter
    cout << "All towns:" << endl;
    for (i = 0; i < townList.size(); i++) {
        townList.at(i).PrintDetails(); // Print details of each town
    }
}

int main() {
    SmallCities app; // SmallCities object
    app.InputTowns(); // Input towns
    app.PrintAllTowns(); // Print all towns
    return 0;
}