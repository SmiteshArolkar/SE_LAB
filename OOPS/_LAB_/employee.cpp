/*
Write a C++ program to store the following details of n' employees in a file data structure (name, id, designation, address, salary)
print the name and salary of all the employees as the output whose designation is "engineer".
 Use the appropriate concepts wherever required
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee
{
    string name;
    int id;
    string designation;
    string address;
    double salary;
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *employees = new Employee[n];

    // Input employees' details
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> employees[i].name;
        cout << "Enter the ID of employee " << i + 1 << ": ";
        cin >> employees[i].id;
        cout << "Enter the designation of employee " << i + 1 << ": ";
        cin >> employees[i].designation;
        cout << "Enter the address of employee " << i + 1 << ": ";
        cin >> employees[i].address;
        cout << "Enter the salary of employee " << i + 1 << ": ";
        cin >> employees[i].salary;
    }

    // Write employees' details to file
    ofstream outFile;
    outFile.open("employees.txt", ios::out);
    if (!outFile)
    {
        cerr << "Error opening employees.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        outFile << employees[i].name << ", " << employees[i].id << ", " << employees[i].designation << ", " << employees[i].address << ", " << employees[i].salary << endl;
    }

    outFile.close();

    // Print name and salary of engineers
    ifstream inFile;
    inFile.open("employees.txt", ios::in);
    if (!inFile)
    {
        cerr << "Error opening employees.txt" << endl;
        return 1;
    }

    cout << "Engineers:" << endl;
    while (!inFile.eof())
    {
        string name;
        int id;
        string designation;
        string address;
        double salary;
        inFile >> name >> id >> designation >> address >> salary;
        if (designation == "engineer")
        {
            cout << "Name: " << name << ", Salary: " << salary << endl;
        }
    }

    inFile.close();
    delete[] employees;
    return 0;
}
