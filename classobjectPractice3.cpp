#include <iostream>
#include <string>
using namespace std;

//member class printing name, height and weight of a person
class Member {
    public:
        void SetName(string customName); //declaration of function to set name
        void SetHeight(double customHeight); //declaration of function to set height
        void SetAge(int customAge); //declaration of function to set age
        string GetName(); //declaration of function to get name
        double GetHeight(); //declaratvoiion of function to get height
        int GetAge(); //declaration of function to get age
    private:
        string name; //private member variable to store name
        double height; //private member variable to store height
        int age; //private member variable to store age
};

void Member::SetName(string customName) { //defining function to set name
    name = customName;
}
void Member::SetHeight(double customHeight) { //defining function to set height
    height = customHeight;
}
void Member::SetAge(int customAge) { //defining function to set age
    age = customAge;
}

string Member::GetName() { //defining function to get name
    return name;
}
double Member::GetHeight() { //defining function to get height
    return height;
}
int Member::GetAge() { //defining function to get age
    return age;
}

int main() {
    Member member1; //creating object of the class
    member1.SetName("John"); //setting name using member function
    member1.SetHeight(5.9); //setting height using member function
    member1.SetAge(30); //setting age using member function

    cout << "Member's name is: " << member1.GetName() << endl; //getting name using member function and displaying it
    cout << "Member's height is: " << member1.GetHeight() << " feet" << endl; //getting height using member function and displaying it
    cout << "Member's age is: " << member1.GetAge() << " years" << endl; //getting age using member function and displaying it

    return 0;
}