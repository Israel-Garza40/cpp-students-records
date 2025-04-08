#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

// Enum for grade levels
enum GradeLevel {
    FRESHMAN,
    SOPHOMORE,
    JUNIOR,
    SENIOR
};

// Type aliases
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

// Student structure
struct Student {
    string name;
    float gpa;
    GradeLevel grade;
};

// Custom namespace for student-related functions
namespace StudentUtils {
    
    void inputStudent(Student &student) {
        cout << "Enter student name: ";
        getline(cin, student.name);

        // GPA validation
        while (true) {
            cout << "Enter GPA (0.00 - 4.00): ";
            cin >> student.gpa;
            if (cin.fail() || student.gpa < 0.0 || student.gpa > 4.0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid GPA. Try again." << endl;
            } else {
                break;
            }
        }

        int gradeInput;
        while (true) {
            cout << "Enter grade level (0: FRESHMAN, 1: SOPHOMORE, 2: JUNIOR, 3: SENIOR): ";
            cin >> gradeInput;
            if (gradeInput >= 0 && gradeInput <= 3) {
                student.grade = static_cast<GradeLevel>(gradeInput);
                cin.ignore(); // Ignore leftover newline
                break;
            } else {
                cout << "Invalid grade level. Try again." << endl;
            }
        }
    }

    void printStudent(const Student &student) {
        string gradeStr[] = {"FRESHMAN", "SOPHOMORE", "JUNIOR", "SENIOR"};
        cout << std::fixed << std::setprecision(2);
        cout << "Name: " << student.name << ", GPA: " << student.gpa
             << ", Grade Level: " << gradeStr[student.grade] << endl;
    }

    void sortStudents(vector<Student> &students) {
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.name < b.name;
        });
    }

    void displayAllSortedStudents(vector<Student> students) {
        sortStudents(students);
        cout << "\nAll Student Records (Sorted Alphabetically):" << endl;
        for (const auto &student : students) {
            printStudent(student);
        }
    }
}

int main() {
    vector<Student> students;
    char choice;

    cout << "Student Record Entry System" << endl;
    do {
        Student newStudent;
        cin.ignore(); // Clear newline before getline
        StudentUtils::inputStudent(newStudent);
        students.push_back(newStudent);

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    StudentUtils::displayAllSortedStudents(students);

    return 0;
}
