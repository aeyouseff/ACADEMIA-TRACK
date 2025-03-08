#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Student class
class Student {
public:
  string fname, lname;
  int id;
  vector<string> Coursesname = {"File Organization", "Multimedia",
                                "Mathematics 4",     "Statistics 2",
                                "Graph Theory",      "Algorithms"};
  vector<int> Coursesgrades = {-1, -1, -1,
                               -1, -1, -1}; // Initialize grades with -1
  vector<float> Coursestotal = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  // Function to enter student info (name and ID)
  void EnterStudentInfo() {
    cout << "Enter student's Name: ";
    cin >> fname >> lname;
    cout << "Enter student's ID: ";
    cin >> id;
  }

  // Function to enter grades for each course
  void EnterGrades() {
    for (int i = 0; i < 6; i++) {
      cout << "Enter grade for " + Coursesname[i] + ": ";
      int grade;
      cin >> grade;
      while (!isValidGrade(grade)) {
        cout << "Invalid grade. Please enter a grade between 0 and 100: ";
        cin >> grade;
      }
      Coursesgrades[i] = grade;
      gradescal();
    }
  }

  // Function to check if the grade entered is valid
  bool isValidGrade(int grade) { return grade >= 0 && grade <= 100; }

  // Function to calculate GPA based on grades
  void gradescal() {
    for (int i = 0; i < 6; i++) {
      if (Coursesgrades[i] >= 95)
        Coursestotal[i] = 4.0;
      else if (Coursesgrades[i] >= 90 && Coursesgrades[i] < 95)
        Coursestotal[i] = 3.7;
      else if (Coursesgrades[i] >= 85 && Coursesgrades[i] < 90)
        Coursestotal[i] = 3.3;
      else if (Coursesgrades[i] >= 80 && Coursesgrades[i] < 85)
        Coursestotal[i] = 3.0;
      else if (Coursesgrades[i] >= 75 && Coursesgrades[i] < 80)
        Coursestotal[i] = 2.7;
      else if (Coursesgrades[i] >= 70 && Coursesgrades[i] < 75)
        Coursestotal[i] = 2.3;
      else if (Coursesgrades[i] >= 65 && Coursesgrades[i] < 70)
        Coursestotal[i] = 2.0;
      else if (Coursesgrades[i] >= 60 && Coursesgrades[i] < 65)
        Coursestotal[i] = 1.7;
      else if (Coursesgrades[i] >= 55 && Coursesgrades[i] < 60)
        Coursestotal[i] = 1.3;
      else if (Coursesgrades[i] >= 50 && Coursesgrades[i] < 55)
        Coursestotal[i] = 1.0;
      else
        Coursestotal[i] = 0.0;
    }
  }

  // Function to calculate the GPA
  float calculateGPA() {
    float totalGrades = 0;
    for (int i = 0; i < 6; i++) {
      totalGrades += Coursestotal[i];
    }
    return totalGrades / 6.0;
  }

  // Function to display student info
  void DisplayStudentInfo() {
    cout << "\n******************************************" << endl;
    cout << "\nStudent Name: " << fname << " " << lname;
    cout << "\nID: " << id << endl;

    bool gradesEntered = false;
    for (int i = 0; i < 6; i++) {
      if (Coursesgrades[i] != -1) {
        gradesEntered = true;
        break;
      }
    }

    if (gradesEntered) {
      cout << "\nGrades and GPA:\n";
      for (int i = 0; i < 6; i++) {
        cout << Coursesname[i] << " - Grade: "
             << (Coursesgrades[i] == -1 ? "Not Entered"
                                        : to_string(Coursesgrades[i]))
             << " (GPA: " << Coursestotal[i] << ")\n";
      }
      cout << "GPA: " << calculateGPA() << endl;
    } else {
      cout << "Grades have not been entered yet. Please enter grades first."
           << endl;
    }
  }

  // Function to save data to file
  void saveToFile() {
    ofstream outFile("student_data.txt");
    outFile << fname << " " << lname << " " << id << endl;
    for (int i = 0; i < 6; i++) {
      outFile << Coursesname[i] << ": "
              << (Coursesgrades[i] == -1 ? "Not Entered"
                                         : to_string(Coursesgrades[i]))
              << " (GPA: " << Coursestotal[i] << ")\n";
    }
    outFile << "GPA: " << calculateGPA() << endl;
    outFile.close();
    cout << "Data saved successfully!" << endl;
  }

  // Function to analyze student's best and worst subjects
  void analyzeBestAndWorstSubject() {
    if (Coursesgrades[0] == -1) {
      cout << "Grades have not been entered yet.";
      return;
    }

    int bestGradeIndex = 0, worstGradeIndex = 0;
    for (int i = 1; i < 6; i++) {
      if (Coursesgrades[i] > Coursesgrades[bestGradeIndex]) {
        bestGradeIndex = i;
      }
      if (Coursesgrades[i] < Coursesgrades[worstGradeIndex]) {
        worstGradeIndex = i;
      }
    }

    cout << "\nBest Subject: " << Coursesname[bestGradeIndex] << " with grade "
         << Coursesgrades[bestGradeIndex] << endl;
    cout << "Worst Subject: " << Coursesname[worstGradeIndex] << " with grade "
         << Coursesgrades[worstGradeIndex] << endl;
  }
};

// Main function
int main() {
  unordered_map<int, Student> students; // Store multiple students
  int choice, studentID;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Enter Student Info (Name and ID)\n";
    cout << "2. Enter Grades\n";
    cout << "3. Calculate and Display GPA\n";
    cout << "4. Display Student Info\n";
    cout << "5. Save Data to File\n";
    cout << "6. Analyze Student's Best and Worst Subject\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      Student newStudent;
      newStudent.EnterStudentInfo();
      students[newStudent.id] = newStudent;
      break;
    }
    case 2:
      cout << "Enter student ID: ";
      cin >> studentID;
      if (students.find(studentID) != students.end()) {
        students[studentID].EnterGrades();
      } else {
        cout << "Student ID not found." << endl;
      }
      break;
    case 3:
      cout << "Enter student ID: ";
      cin >> studentID;
      if (students.find(studentID) != students.end()) {
        students[studentID].DisplayStudentInfo();
      } else {
        cout << "Student ID not found." << endl;
      }
      break;
    case 4:
      cout << "Enter student ID: ";
      cin >> studentID;
      if (students.find(studentID) != students.end()) {
        students[studentID].DisplayStudentInfo();
      } else {
        cout << "Student ID not found." << endl;
      }
      break;
    case 5:
      cout << "Enter student ID: ";
      cin >> studentID;
      if (students.find(studentID) != students.end()) {
        students[studentID].saveToFile();
      } else {
        cout << "Student ID not found." << endl;
      }
      break;
    case 6:
      cout << "Enter student ID: ";
      cin >> studentID;
      if (students.find(studentID) != students.end()) {
        students[studentID].analyzeBestAndWorstSubject();
      } else {
        cout << "Student ID not found." << endl;
      }
      break;
    case 7:
      cout << "Exiting the program...\n";
      return 0;
    default:
      cout << "Invalid choice, please try again.\n";
    }
  }

  return 0;
}
