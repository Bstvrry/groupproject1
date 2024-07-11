#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Structure to represent a student
struct Student {
    string firstname;
    string sirname;
    char Gender;
    int Age;
    int Group;
    vector<string> activities;
};

// Structure to represent a club/society
struct Club {
    string name;
    int capacity;
    int maleCount;
    int femaleCount;
};

// Structure to represent a sport
struct Sport {
    string name;
    int capacity;
    int maleCount;
    int femaleCount;
};

// Function to display the main menu
void displayMainMenu() {
    cout <<"\nCo-curricular Activity Selection System.\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. View Clubs/Societies\n";
    cout << "4. View Sports\n";
    cout << "5. View Grouped Students\n";
    cout << "6. Save Data\n";
    cout << "7. Open Saved Data\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

