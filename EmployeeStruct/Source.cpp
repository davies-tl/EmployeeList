/* 
Analysis: Create a struct employee, read data from keyboard to struct, then output struct

Design:
   Input-> Employee name, hours worked, pay rate, and salary
   Process-> Declare a structure to represent an employee (input data received from keyboard)
             Functions:
                read: from keyboard name, hours, pay
                print: name, salary each on one line labeled
                calculate salary: calculate the salary for an employee; over time is for hours greater than 40 pay is 1.5 times
   Output-> Use print function
*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct employeeInfo {
    string employeeName;
    float hoursWorked;
    float payRate;
    double totalSalary;
};

employeeInfo ReadStruct(employeeInfo userInfo);
employeeInfo CalculateHours(employeeInfo userInfo);
void PrintStruct(employeeInfo userInfo);

int main() {
    employeeInfo userEmployee;

    cout << left << fixed << showpoint << setprecision(2);

    userEmployee = ReadStruct(userEmployee);
    userEmployee = CalculateHours(userEmployee);
    PrintStruct(userEmployee);

    exit(0);
}

employeeInfo ReadStruct(employeeInfo userInfo) {
    cout << "Enter Employee Name: ";
    getline(cin, userInfo.employeeName);
    cout << "Enter Total Hours Worked: ";
    cin >> userInfo.hoursWorked;
    cout << "Enter Pay Rate: $";
    cin >> userInfo.payRate;
    
    return userInfo;
}

employeeInfo CalculateHours(employeeInfo userInfo) {
    float overtimeHours;

    if (userInfo.hoursWorked > 40) {
        overtimeHours = userInfo.hoursWorked - 40.0;
        userInfo.hoursWorked = userInfo.hoursWorked - overtimeHours;
        userInfo.totalSalary = (userInfo.hoursWorked * userInfo.payRate) + ((overtimeHours * 1.5) * userInfo.payRate);
    }
    else {
        userInfo.totalSalary = userInfo.hoursWorked * userInfo.payRate;
    }
    
    return userInfo;
}

void PrintStruct(employeeInfo userInfo) {
    cout << endl;
    cout << "\n";
    cout << "\n Employee Name: " << setw(20) << userInfo.employeeName << "Salary: $" << userInfo.totalSalary << endl;
}