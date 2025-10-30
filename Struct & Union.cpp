#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int NUM_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int findHighestScore(studentType students[], int size);
void printHighestScorers(studentType students[], int size, int highest);
void printAllStudents(studentType students[], int size);

int main() {
    studentType students[NUM_STUDENTS];
    int highestScore;

    readData(students, NUM_STUDENTS);
    assignGrade(students, NUM_STUDENTS);
    highestScore = findHighestScore(students, NUM_STUDENTS);

    cout << "\n--- Students Data ---\n";
    printAllStudents(students, NUM_STUDENTS);

    cout << "\nHighest Score: " << highestScore << endl;
    printHighestScorers(students, NUM_STUDENTS, highestScore);

    return 0;
}

void readData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name for student " << i + 1 << ": ";
        cin >> students[i].studentFName;
        cout << "Enter last name for student " << i + 1 << ": ";
        cin >> students[i].studentLName;
        cout << "Enter test score (0-100): ";
        cin >> students[i].testScore;
        cout << endl;
    }
}

void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

void printHighestScorers(studentType students[], int size, int highest) {
    cout << "\nStudents with the highest score:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highest) {
            cout << students[i].studentLName << ", " 
                 << students[i].studentFName
                 << "  Score: " << students[i].testScore << endl;
        }
    }
}

void printAllStudents(studentType students[], int size) {
    cout << "Name\t\t\tScore\tGrade\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << students[i].studentLName << ", " << students[i].studentFName;
        int nameLength = students[i].studentLName.length() + students[i].studentFName.length() + 2;
        if (nameLength < 15) cout << "\t\t";
        else if (nameLength < 23) cout << "\t";
        cout << students[i].testScore << "\t" << students[i].grade << endl;
    }
}
