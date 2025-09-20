#include <iostream>
#include <vector>

using namespace std;

// program first reads integer memberCount from input
// representing number of pairs of inputs to be read
// each pair has a string and a character representing the member's name and group
// if GetGroup() returns value 'B', then PrintInfo() is called to output the member's details

class Member {
    public:
        void SetDetails(string newName, char newGroup);
        char GetGroup() const;
        void PrintInfo() const;
    private:
        string name;
        char group;
};

void Member::SetDetails(string newName, char newGroup) {
    name = newName;
    group = newGroup;
}

char Member::GetGroup() const{
    return group;
}

char Member::PrintInfo() const {
    cout << "Member: " << name << ", Group: " << group << endl;
}

int main() {
    vector<Member> memberList; // Vector to store members
    Member currMember; // Current member object
    string currName;
    char currGroup;
    int memberCount;
    unsigned int i; // Loop counter

    cout << "Type number of members:" << endl;
    cin >> memberCount;
    cin.ignore(); // Ignore newline character after integer input

    for (i = 0; i < static_cast<unsigned int>(memberCount); i++) {
        cout << "Type name and group (A, B, or C):" << endl;
        getline(cin, currName);
        cin >> currGroup;
        cin.ignore(); // Ignore newline character after character input

        currMember.SetDetails(currName, currGroup); // Set name and group
        memberList.push_back(currMember); // Add current member to the list
    }

    // Output all members in group A
    cout << endl << "Members in group A:" << endl;
    for (i = 0; i < memberList.size(); i++) {
        currMember = memberList.at(i);
        if (currMember.GetGroup() == 'B') { // Check if group is 'B'
            currMember.PrintInfo();
        }
    }

    return 0;
}