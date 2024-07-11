
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
