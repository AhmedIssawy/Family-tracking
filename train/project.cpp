#include <iostream> //Youssef Hany
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string subjects[5];
};

Student students[100];
int studentCount = 0;

void fillStudentData() {
    if (studentCount >= 100) {
        cout << "Student limit reached!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[studentCount].id;

    cout << "Enter student name: ";
    cin >> students[studentCount].name;

    cout << "Enter 5 subjects:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> students[studentCount].subjects[i];
    }

    studentCount++;
    cout << "Student data added successfully!\n";
}

void printStudentData() {
    if (studentCount == 0) {
        cout << "No students found!\n";
        return;
    }

    for (int i = 0; i < studentCount; ++i) {
        cout << "Student ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Subjects: ";
        for (int j = 0; j < 5; ++j) {
            cout << students[i].subjects[j] << (j < 4 ? ", " : "");
        }
        cout << "\n\n";
    }
}

void searchByID() {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            cout << "Student found:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Subjects: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].subjects[j] << (j < 4 ? ", " : "");
            }
            cout << "\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found!\n";
}

void searchByName() {
    string name;
    cout << "Enter student name to search: ";
    cin >> name;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].name == name) {
            cout << "Student found:\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Subjects: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].subjects[j] << (j < 4 ? ", " : "");
            }
            cout << "\n";
            return;
        }
    }
    cout << "Student with name " << name << " not found!\n";
}

void searchBySubjectName() {
    string subject;
    cout << "Enter subject name to search: ";
    cin >> subject;

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (students[i].subjects[j] == subject) {
                if (!found) {
                    cout << "Students enrolled in " << subject << ":\n";
                    found = true;
                }
                cout << "ID: " << students[i].id << ", Name: " << students[i].name << "\n";
                break;
            }
        }
    }
    if (!found) {
        cout << "No students found enrolled in " << subject << "!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Fill student data\n";
        cout << "2. Print student data\n";
        cout << "3. Search by ID\n";
        cout << "4. Search by name\n";
        cout << "5. Search by subject name\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                fillStudentData();
                break;
            case 2:
                printStudentData();
                break;
            case 3:
                searchByID();
                break;
            case 4:
                searchByName();
                break;
            case 5:
                searchBySubjectName();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
