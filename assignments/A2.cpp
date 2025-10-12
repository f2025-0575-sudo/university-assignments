#include <iostream>
#include <iomanip> // for setw()
using namespace std;

int main() {
    float sub1, sub2, sub3, sub4, sub5;
    float total, percentage;
    string grade;

    // Taking input for 5 subjects
    cout << "Enter marks in 5 subjects (out of 100): " << endl;
    cout << "Subject 1: "; cin >> sub1;
    cout << "Subject 2: "; cin >> sub2;
    cout << "Subject 3: "; cin >> sub3;
    cout << "Subject 4: "; cin >> sub4;
    cout << "Subject 5: "; cin >> sub5;

    // Calculating total and percentage
    total = sub1 + sub2 + sub3 + sub4 + sub5;
    percentage = total / 5.0;

    // Assigning grade
    if (percentage >= 90)
        grade = "A+";
    else if (percentage >= 80)
        grade = "A";
    else if (percentage >= 70)
        grade = "B";
    else if (percentage >= 60)
        grade = "C";
    else if (percentage >= 50)
        grade = "D";
    else
        grade = "F";

    // Using ternary operator for pass/fail
    string result = (percentage >= 50) ? "Pass" : "Fail";

    // Displaying formatted report card
    cout << "\n\n========== Report Card ==========\n";
    cout << left << setw(20) << "Subject" << setw(10) << "Marks" << endl;
    cout << "----------------------------------\n";
    cout << left << setw(20) << "Subject 1" << setw(10) << sub1 << endl;
    cout << left << setw(20) << "Subject 2" << setw(10) << sub2 << endl;
    cout << left << setw(20) << "Subject 3" << setw(10) << sub3 << endl;
    cout << left << setw(20) << "Subject 4" << setw(10) << sub4 << endl;
    cout << left << setw(20) << "Subject 5" << setw(10) << sub5 << endl;
    cout << "----------------------------------\n";
    cout << left << setw(20) << "Total Marks" << setw(10) << total << endl;
    cout << left << setw(20) << "Percentage" << setw(10) << fixed << setprecision(2) << percentage << "%" << endl;
    cout << left << setw(20) << "Grade" << setw(10) << grade << endl;
    cout << left << setw(20) << "Result" << setw(10) << result << endl;
    cout << "==================================\n";

    return 0;
}