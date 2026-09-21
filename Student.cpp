#include "Student.h"
#include <fstream>
#include <iostream>
#include <iomanip>

Student::Student(const std::string& studentName,
                 const std::string& studentId,
                 double studentGpa)
    : name(studentName), id(studentId), gpa(studentGpa) {}

void Student::display() const {
    std::cout << "Name: " << name
              << " | ID: " << id
              << " | GPA: " << std::fixed << std::setprecision(2)
              << gpa << '\n';
}

const std::string& Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

void Student::saveToFile(const std::vector<Student>& students,
                         const std::string& filename) {
    std::ofstream output(filename);

    if (!output) {
        std::cerr << "Error: Could not open " << filename << " for writing.\n";
        return;
    }

    for (const Student& student : students) {
        output << student.name << '|'
               << student.id << '|'
               << student.gpa << '\n';
    }
}
