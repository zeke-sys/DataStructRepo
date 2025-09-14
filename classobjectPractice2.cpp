#include <iostream>
#include <string>
using namespace std;

//creating person class and practicing public and private access specifiers and scope resolution operator
class Person {
    public:
        void setName(string personName); //declaration of function to set name
        string getName(); //declaration of function to get name
    private:
        string name; //private member variable to store name
};

void Person::setName(string personName) { //defining function to set name
    name = personName;
}

string Person::getName() { //defining function to get name
    return name;
}

int main() {
    Person person1; //creating object of the class
    person1.setName("Alice"); //setting name using member function
    cout << "Person's name is: " << person1.getName() << endl; //getting name using member function and displaying it

    return 0;
}