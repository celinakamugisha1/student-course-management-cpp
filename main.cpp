#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

void displayMenu() {
    cout << "\n===== Student Course Management System =====\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Search for student\n";
    cout << "4. Calculate average GPA\n";
    cout << "5. Save students to file\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                string name, id;
                double gpa;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter student name: ";
                getline(cin, name);

                cout << "Enter student ID: ";
                getline(cin, id);

                cout << "Enter GPA (0.0 - 4.0): ";
                cin >> gpa;

                if (gpa < 0.0 || gpa > 4.0) {
                    cout << "Invalid GPA. Student was not added.\n";
                } else {
                    students.emplace_back(name, id, gpa);
                    cout << "Student added successfully.\n";
                }
                break;
            }

            case 2:
                if (students.empty()) {
                    cout << "No students currently stored.\n";
                } else {
                    for (const Student& student : students) {
                        student.display();
                    }
                }
                break;

            case 3: {
                string id;
                cout << "Enter student ID to search: ";
                cin >> id;

                bool found = false;
                for (const Student& student : students) {
                    if (student.getId() == id) {
                        student.display();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 4:
                if (students.empty()) {
                    cout << "No students available to calculate an average.\n";
                } else {
                    double total = 0.0;
                    for (const Student& student : students) {
                        total += student.getGpa();
                    }
                    cout << "Average GPA: " << total / students.size() << '\n';
                }
                break;

            case 5: {
                if (students.empty()) {
                    cout << "No students to save.\n";
                } else {
                    Student::saveToFile(students, "students.txt");
                    cout << "Student data saved to students.txt.\n";
                }
                break;
            }

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Please select an option from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}
