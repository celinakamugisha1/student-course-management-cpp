#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::string id;
    double gpa;

public:
    Student(const std::string& studentName,
            const std::string& studentId,
            double studentGpa);

    void display() const;

    const std::string& getId() const;
    double getGpa() const;

    static void saveToFile(const std::vector<Student>& students,
                           const std::string& filename);
};

#endif
