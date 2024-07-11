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

// Function to add a new student
void addStudent(vector<Student>& students, vector<Club>& clubs, vector<Sport>& sports) {
    Student newStudent;
    cout << "\nEnter Student First name: ";
    cin >> newStudent.firstname;
    cout << "Enter Student Last Name: ";
    cin >> newStudent.sirname;
    cout << "Enter Student Gender (M/F): ";
    cin >> newStudent.Gender;
    cout << "Enter Student Age: ";
    cin >> newStudent.Age;
    cout << "Enter Student Group (1-3): ";
    cin >> newStudent.Group;

    cout << "Choose activities (enter the names separated by space, type 'end' to finish): ";
    string activity;
    while (cin >> activity && activity != "end") {
        newStudent.activities.push_back(activity);
    }

    for (const auto& activity : newStudent.activities) {
        bool found = false;
        for (auto& club : clubs) {
            if (club.name == activity) {
                if (newStudent.Gender == 'M') club.maleCount++;
                else if (newStudent.Gender == 'F') club.femaleCount++;
                found = true;
                break;
            }
        }
        if (!found) {
            for (auto& sport : sports) {
                if (sport.name == activity) {
                    if (newStudent.Gender == 'M') sport.maleCount++;
                    else if (newStudent.Gender == 'F') sport.femaleCount++;
                    break;
                }
            }
        }
    }

    students.push_back(newStudent);
    cout << "\nStudent added successfully!\n";
}

// Function to display all students
void viewStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students added yet.\n";
        return;
    }
    cout << "\nStudent List:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.firstname << " " << student.sirname << endl;
        cout << "Gender: " << student.Gender << endl;
        cout << "Age: " << student.Age << endl;
        cout << "Group: " << student.Group << endl;
        cout << "Activities: ";
        if (student.activities.empty()) {
            cout << "None\n";
        } else {
            for (const auto& activity : student.activities) {
                cout << activity << " ";
            }
            cout << endl;
        }
        cout << "---------------------\n";
    }
}
