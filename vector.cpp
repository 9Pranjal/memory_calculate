#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin >> s.name;
    students.push_back(s);
    cout << "Student added\n";
}

void displayStudents() {
    if (students.size() == 0) {
        cout << "No students\n";
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << "\n";
    }
}

void removeStudent() {
    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            for (int j = i; j < students.size() - 1; j++) {
                students[j] = students[j + 1];
            }
            students.pop_back();
            cout << "Student removed\n";
            return;
        }
    }
    cout << "Student not found\n";
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "ID: " << students[i].id << ", Name: " << students[i].name << "\n";
            return;
        }
    }
    cout << "Student not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display Students\n3. Remove Student\n4. Search Student\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while(choice != 5);
    return 0;
}
