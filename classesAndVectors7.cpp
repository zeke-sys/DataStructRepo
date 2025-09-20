#include <iostream>
#include <vector>
using namespace std;

//program first reads integer studentCount from input
//representing number of pairs of inputs to be read
//each pair has a string and a character representing a student's name and group
//one student object is created for each pair and added to vector studentList
//Appointments class uses PrintSelectedStudents() function to output student objects with group 'A'

class Student {
    public:
        void SetDetails(string newName, char newGroup);
        char GetGroup() const;
        void PrintDetails() const;
    private:
        string name;
        char group;
};

void Student::SetDetails(string newName, char newGroup) {
    name = newName;
    group = newGroup;
}

char Student::GetGroup() const {
    return group;
}

void Student::PrintDetails() const {
    cout << "Student Name: " << name << ", Group: " << group << endl;
}

class Appointments {
    public:
        void InputStudents();
        void PrintSelectedStudents();
    private:
        vector<Student> studentList; // Vector to store students
};

void Appointments::InputStudents() {
    Student currStudent; // Current student object
    string currName;
    char currGroup;
    int studentCount;
    unsigned int i; // Loop counter

    cout << "Type number of students:" << endl;
    cin >> studentCount;
    cin.ignore(); // Ignore newline character after integer input
    for (i = 0; i < static_cast<unsigned int>(studentCount); i++) {
        cout << "Type student name:" << endl;
        getline(cin, currName);
        cout << "Type student group (A/B):" << endl;
        cin >> currGroup;
        cin.ignore(); // Ignore newline character after character input
        currStudent.SetDetails(currName, currGroup); // Set student details
        studentList.push_back(currStudent); // Add current student to the list
    }
}

void Appointments::PrintSelectedStudents() {
    Student currStudent; // Current student object
    unsigned int i; // Loop counter

    cout << endl << "Students in group A:" << endl;
    for (i = 0; i < studentList.size(); i++) {
        currStudent = studentList.at(i);
        if (currStudent.GetGroup() == 'A') {
            currStudent.PrintDetails(); // Print student details
        }
    }
}

int main() {
    Appointments app; // Appointments object
    app.InputStudents(); // Input student details
    app.PrintSelectedStudents(); // Print students in group A
    return 0;
}

