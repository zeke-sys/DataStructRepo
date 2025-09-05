#include <iostream>
#include <string>

using namespace std;

//creating restaturant class and calling functions to operate on the object of the class

class Restaurant {
private:
    string name;
    float rating;

public:
    void SetName(string restaurantName) {
        name = restaurantName;
    }
    void SetRating(float restaurantRating) {
        rating = restaurantRating;
    }
    void DisplayInfo() const { //function to display the information of the restaurant
        cout << name << " - Rating: " << rating << endl;
    }
};

int main() {
    Restaurant restaurant1; //creating object of the class
    restaurant1.SetName("The Gourmet Kitchen");
    restaurant1.SetRating(4.5);

    Restaurant restaurant2; //creating another object of the class
    restaurant2.SetName("Pizza Palace");
    restaurant2.SetRating(4.2);

    cout << "The two restaurants are: " << endl;
    restaurant1.DisplayInfo();
    restaurant2.DisplayInfo();

    return 0;
}