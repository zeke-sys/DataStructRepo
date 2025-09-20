#include <iostream>
#include <vector>
using namespace std;

// program reads integer lineNumber from iput using cin
// until next line read is equal to -99
// otherwise, currCertificate's ReadDetails() reads the certificate's details
// and append currCertificate to vector certificateList

class Certificate {
    public:
        void ReadDetails();
        void PrintDetails() const;
    private:
        string holder;
        int level;
};

void Certificate::ReadDetails() {
    cout << "Type certificate holder's name:" << endl;
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, holder);
    cout << "Type certificate level (1-5):" << endl;
    cin >> level;
}

void Certificate::PrintDetails() const {
    cout << "Certificate holder: " << holder << ", Level: " << level << endl;
}

int main() {
    vector<Certificate> certificateList; // Vector to store certificates
    Certificate currCertificate; // Current certificate object
    int lineNumber;
    unsigned int i; // Loop counter

    cout << "Type line number (-99 to end):" << endl;
    cin >> lineNumber;
    while (lineNumber != -99) {
        currCertificate.ReadDetails(); // Read certificate details
        certificateList.push_back(currCertificate); // Add current certificate to the list

        cout << "Type line number (-99 to end):" << endl;
        cin >> lineNumber;
    }

    // Output all certificates
    cout << endl << "Certificates entered:" << endl;
    for (i = 0; i < certificateList.size(); i++) {
        currCertificate = certificateList.at(i);
        currCertificate.PrintDetails(); // Print certificate details
    }
    return 0;
}