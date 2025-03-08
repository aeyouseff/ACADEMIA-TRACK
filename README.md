# ACADEMIA-TRACK - Student Grade Management System

**ACADEMIA-TRACK** is a comprehensive Student Grade Management System designed for **Faculty of Computer Science**, **Nahda University**. This system allows faculty members and students to input, manage, and analyze student grades and GPA. It provides an easy-to-use interface to manage academic records, calculate GPA, and track student performance over time.

---

## Features

- **Student Info Management**: Ability to store and manage student details (name, ID).
- **Grade Input**: Facilitates entering grades for various subjects/courses.
- **GPA Calculation**: Automatically calculates GPA based on the inputted grades.
- **Subject Analysis**: Analyzes and displays the best and worst-performing subjects for each student.
- **Data Storage**: Saves student data and GPA to a file (`student_data.txt`) for persistence.
- **File I/O**: Load and save data to and from text files, enabling data persistence between sessions.
- **Interactive Command-Line Interface**: An easy-to-use CLI for interacting with the system.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [System Design](#system-design)
6. [Screenshots](#screenshots)
7. [License](#license)
8. [Future Improvements](#future-improvements)
9. [Contact](#contact)

---

## Introduction

**ACADEMIA-TRACK** is a student grade management system designed specifically for **Nahda University’s Faculty of Computer Science**. The system allows students to enter their grades, calculate their GPA, and provides analysis on their performance across various courses. Additionally, the system allows faculty members to store, view, and analyze student data.

The main goal of this project is to provide a simple tool to manage academic progress and make it easier for students and faculty to track academic performance.

---

## Installation

To run the **ACADEMIA-TRACK** system on your local machine, you'll need a C++ compiler. Follow these steps to set up the project:

### 1. Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/aeyouseff/ACADEMIA-TRACK.git
```

### 2. Compile the Code

Navigate to the project folder and compile the code using a C++ compiler such as **g++**:

```bash
cd ACADEMIA-TRACK
g++ -o AcademiaTrack main.cpp
```

### 3. Run the Program

After compilation, run the program using the following command:

```bash
./AcademiaTrack
```

---

## Usage

Once the program is running, you will be presented with a menu offering the following choices:

1. **Enter Student Info**: You can input a student's name and ID.
2. **Enter Grades**: Enter grades for the six subjects. These grades should be in the range of 0 to 100.
3. **Calculate and Display GPA**: After entering the grades, the program automatically calculates and displays the GPA based on the grades entered.
4. **Display Student Info**: View all the information for a specific student by entering their ID.
5. **Save Data to File**: The system will save student data to a text file (`student_data.txt`) for future reference.
6. **Analyze Best and Worst Subjects**: Analyze the best and worst-performing subjects based on the grades entered.
7. **Exit**: Exit the program.

### Example Interaction

```
Menu:
1. Enter Student Info (Name and ID)
2. Enter Grades
3. Calculate and Display GPA
4. Display Student Info
5. Save Data to File
6. Analyze Student's Best and Worst Subject
7. Exit
Enter your choice: 1
Enter student's Name: Ahmed Yousef
Enter student's ID: 12345
```

---

## System Design

### Overview

The system consists of the following components:
- **Student Class**: Stores student information such as name, ID, grades, and GPA.
- **Grade Calculation**: Uses a predefined grading scale to calculate GPA based on the grades entered.
- **File I/O**: Reads and writes student data to and from a text file to preserve data between sessions.
- **Best and Worst Subject Analysis**: Analyzes the best and worst-performing subjects for each student based on grades.

### GPA Calculation Logic

The GPA is calculated using the following scale:

- **A**: 95-100 (4.0 GPA)
- **A-**: 90-94 (3.7 GPA)
- **B+**: 85-89 (3.3 GPA)
- **B**: 80-84 (3.0 GPA)
- **B-**: 75-79 (2.7 GPA)
- **C+**: 70-74 (2.3 GPA)
- **C**: 65-69 (2.0 GPA)
- **C-**: 60-64 (1.7 GPA)
- **D+**: 55-59 (1.3 GPA)
- **D**: 50-54 (1.0 GPA)
- **F**: <50 (0.0 GPA)

---

## Screenshots

Here are some sample outputs from the program:

**Enter Student Information**
```
Enter student's Name: Ahmed Yousef
Enter student's ID: 12345
```

**Enter Grades for Courses**
```
Enter grade for File Organization: 88
Enter grade for Multimedia: 92
Enter grade for Mathematics 4: 85
Enter grade for Statistics 2: 78
Enter grade for Graph Theory: 90
Enter grade for Algorithms: 87
```

**GPA Calculation and Display**
```
Student Name: Ahmed Yousef
ID: 12345
Grades and GPA:
File Organization - Grade: 88 (GPA: 3.3)
Multimedia - Grade: 92 (GPA: 3.7)
Mathematics 4 - Grade: 85 (GPA: 3.3)
Statistics 2 - Grade: 78 (GPA: 2.7)
Graph Theory - Grade: 90 (GPA: 3.7)
Algorithms - Grade: 87 (GPA: 3.3)
GPA: 3.38
```

---

## Future Improvements

- **More Course Support**: Add the ability to support more courses or allow the user to add their own courses dynamically.
- **Graphical User Interface (GUI)**: Create a GUI for better user experience using frameworks like Qt or Tkinter.
- **Export and Import Data**: Enable CSV or Excel import/export for handling student data.
- **Semester-wise Tracking**: Track students' grades across multiple semesters and calculate their cumulative GPA (CGPA).
- **Authentication**: Implement user authentication to secure access to the system (faculty and student roles).
- **Performance Analytics**: Advanced analytics to show trends in performance over semesters or years.

---
