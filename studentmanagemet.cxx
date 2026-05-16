
#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
};

vector<Student> students;

void addStudent() {
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.roll;

    cin.ignore(); // important to avoid input bug

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.size() == 0) {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n=================================\n";
    cout << "       STUDENT LIST\n";
    cout << "=================================\n";
    cout << "Roll\tName\t\tMarks\n";

    for (auto s : students) {
        cout << s.roll << "\t" << s.name << "\t\t" << s.marks << "\n";
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    for (auto s : students) {
        if (s.roll == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll: " << s.roll << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Marks: " << s.marks << "\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void updateStudent() {
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.roll == roll) {

            cin.ignore();

            cout << "Enter new name: ";
            getline(cin, s.name);

            cout << "Enter new marks: ";
            cin >> s.marks;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n=================================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}