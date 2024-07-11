
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
#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
