// program for slection of activities
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
// Function to display all sports
void viewSports(const vector<Sport>& sports) {
    if (sports.empty()) {
        cout << "\nNo sports added yet.\n";
        return;
    }
    cout << "\nSport List:\n";
    for (const auto& sport : sports) {
        cout << "Name: " << sport.name << endl;
        cout << "Capacity: " << sport.capacity << endl;
        cout << "Male Count: " << sport.maleCount << endl;
        cout << "Female Count: " << sport.femaleCount << endl;
        cout << "---------------------\n";
    }
}
// Function to display all clubs/societies
void viewClubs(const vector<Club>& clubs) {
    if (clubs.empty()) {
        cout << "\nNo clubs/societies added yet.\n";
        return;
    }
    cout << "\nClub/Society List:\n";
    for (const auto& club : clubs) {
        cout << "Name: " << club.name << endl;
        cout << "Capacity: " << club.capacity << endl;
        cout << "Male Count: " << club.maleCount << endl;
        cout << "Female Count: " << club.femaleCount << endl;
        cout << "---------------------\n";
    }
}


// Function to view grouped students
void viewGroupedStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo students added yet.\n";
        return;
    }
    cout << "\nGrouped Student List:\n";
    for (int i = 1; i <= 3; ++i) {
        cout << "\nGroup " << i << ":\n";
        for (const auto& student : students) {
            if (student.Group == i) {
                cout << "Name: " << student.firstname << " " << student.sirname << endl;
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
    }
}

// Function to save data to a CSV file
void saveData(const vector<Student>& students, const vector<Club>& clubs, const vector<Sport>& sports) {
    ofstream outputFile("data.csv");
    if (outputFile.is_open()) {
        // Write student data
        outputFile << "Student,Firstname,last name,Gender,Age,Group,Activities\n";
        for (const auto& student : students) {
            outputFile << "Student," << student.firstname << "," << student.sirname << "," << student.Gender << ","
                      << student.Age << "," << student.Group << ",";
            for (const auto& activity : student.activities) {
                outputFile << activity << " ";
            }
            outputFile << "\n";
        }

        // Write club/society data
        outputFile << "\nClub,Name,Capacity,MaleCount,FemaleCount\n";
        for (const auto& club : clubs) {
            outputFile << "Club," << club.name << "," << club.capacity << "," << club.maleCount << ","
                      << club.femaleCount << "\n";
        }

        // Write sport data
        outputFile << "\nSport,Name,Capacity,MaleCount,FemaleCount\n";
        for (const auto& sport : sports) {
            outputFile << "Sport," << sport.name << "," << sport.capacity << "," << sport.maleCount << ","
                      << sport.femaleCount << "\n";
        }
        outputFile.close();
        cout << "\nData saved successfully to data.csv!\n";
    } else {
        cout << "\nError opening file for saving data.\n";
    }
}

// Function to open and read the saved CSV file
void openSavedData() {
    ifstream inputFile("data.csv");
    if (inputFile.is_open()) {
        string line;
        cout << "\nReading data from data.csv:\n";
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "\nError opening file for reading data.\n";
    }
}

int main() {
    // Initialize vectors for students, clubs/societies, and sports
    vector<Student> students;
    vector<Club> clubs;
    vector<Sport> sports;


    // Initialize sports
    sports.push_back({"Rugby", 20, 0, 0});
    sports.push_back({"Athletics", 20, 0, 0});
    sports.push_back({"Swimming", 20, 0, 0});
    sports.push_back({"Soccer", 20, 0, 0});

      // Initialize clubs/societies
    clubs.push_back({"Journalism Club", 60, 0, 0});
    clubs.push_back({"Red Cross Society", 60, 0, 0});
    clubs.push_back({"AISEC", 60, 0, 0});
    clubs.push_back({"Business Club", 60, 0, 0});
    clubs.push_back({"Computer Science Club", 60, 0, 0});

    // Main program loop
    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent(students, clubs, sports);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
                viewClubs(clubs);
                break;
            case 4:
                viewSports(sports);
                break;
            case 5:
                viewGroupedStudents(students);
                break;
            case 6:
                saveData(students, clubs, sports);
                break;
            case 7:
                openSavedData();
                break;
            case 8:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
