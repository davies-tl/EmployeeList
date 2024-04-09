#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#define CAP 100

using namespace std;

struct employeeInfo {
    string employeeName;
    float hoursWorked;
    float payRate;
    double totalSalary;
};

void OpenFile(ifstream& inFS);
int ReadStruct(ifstream& inFS, employeeInfo userInfo[], int size);
employeeInfo CalculateHours(employeeInfo userInfo);
void PrintStruct(employeeInfo userInfo);

int main() {
    int size = CAP;
    ifstream inFile;
    employeeInfo userEmployee[size];

    ReadStruct(inFile, userEmployee, size);
    

    userEmployee = CalculateHours(userEmployee);
    PrintStruct(userEmployee);

    exit(0);
}

void OpenFile(ifstream& inFS) {
    string fileName;

    cout << "Please enter file name.";
    getline(cin, fileName);



}

int ReadStruct(ifstream& inFS, employeeInfo userInfo[], int& size) {
    int i;
    
    OpenFile(inFS);
    
    for (i = 0; i < size; ++i) {
        getline(inFS, userInfo[i].employeeName)


    }
    inFS >> 

    cout << "Enter Employee Name: ";
    getline(cin, userInfo.employeeName);
    cout << "Enter Total Hours Worked: ";
    cin >> userInfo.hoursWorked;
    cout << "Enter Pay Rate: $";
    cin >> userInfo.payRate;
    cin.ignore(10, '\n');

    return size;
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
    cout << left << fixed << showpoint << setprecision(2) << endl;
    cout << "Employee Name: " << setw(20) << userInfo.employeeName << "Salary: $" << userInfo.totalSalary << endl;
}