#include <iostream>
#include <string>
using namespace std;

//creating dog class to find dog age in human years

class Dog {
    public:
        void SetWeightAndAge(int customWeight, int customAge); //declaration of function to set weight and age
        int GetDogAgeInHumanYears(); //declaration of function to get dog age in human years
    private:
        int weight; //private member variable to store weight
        int age; //private member variable to store age
        string size; //private member variable to store size
        int dogAgeInHumanYears; //private member variable to store dog age in human years
        void SetHumanYears(); //declaration of function to set dog age in human years
};

void Dog::SetWeightAndAge(int customWeight, int customAge) { //defining and setting conditions for weight
    weight = customWeight;
    if (weight <= 20) {
        size = "small";
    } else if (weight > 20 && weight <= 50) {
        size = "medium";
    } else {
        size = "large";
    }
    age = customAge;
    SetHumanYears(); //calling function to set dog age in human years
}

void Dog::SetHumanYears() { //defining function to set dog age in human years based on factor
    int factor;

    if (size == "small") {
        factor = 5;
    } else if (size == "medium") {
        factor = 6;
    } else {
        factor = 7;
    }

    dogAgeInHumanYears = age * factor; //calculating dog age in human years
}

int Dog::GetDogAgeInHumanYears() { //defining function to get dog age in human years
    return dogAgeInHumanYears;
}

int main() {
    Dog dog1; //creating object of the class
    dog1.SetWeightAndAge(30, 4); //setting weight and age using member function

    cout << "Dog's age in human years is: " << dog1.GetDogAgeInHumanYears() << " years" << endl; //getting dog age in human years using member function and displaying it
    return 0;
}