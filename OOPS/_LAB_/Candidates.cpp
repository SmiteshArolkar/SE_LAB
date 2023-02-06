/*
Write a C++ program using files to prompt user to enter following information of 'n' number of 
candidates (name, address, course- selected). Filter the candidates' detail depending on the course 
selected (i.e. engineering/medicine/pharmacy) and insert them into separate files named engineering, 
txt, medicine. txt, pharmacy. txt. Use the appropriate file error handling functions.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Candidate
{
    string name;
    string address;
    string course;
};

int main()
{
    int n;
    cout << "Enter the number of candidates: ";
    cin >> n;

    Candidate *candidates = new Candidate[n];

    // Input candidates' details
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of candidate " << i + 1 << ": ";
        cin >> candidates[i].name;
        cout << "Enter the address of candidate " << i + 1 << ": ";
        cin >> candidates[i].address;
        cout << "Enter the course selected by candidate " << i + 1 << " (engineering/medicine/pharmacy): ";
        cin >> candidates[i].course;
    }

    // Filter candidates' details based on the course selected
    ofstream engineeringFile, medicineFile, pharmacyFile;

    engineeringFile.open("engineering.txt", ios::out);
    if (!engineeringFile)
    {
        cerr << "Error opening engineering.txt" << endl;
        return 1;
    }
    medicineFile.open("medicine.txt", ios::out);
    if (!medicineFile)
    {
        cerr << "Error opening medicine.txt" << endl;
        return 1;
    }
    pharmacyFile.open("pharmacy.txt", ios::out);
    if (!pharmacyFile)
    {
        cerr << "Error opening pharmacy.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (candidates[i].course == "engineering")
        {
            engineeringFile << candidates[i].name << ", " << candidates[i].address << endl;
        }
        else if (candidates[i].course == "medicine")
        {
            medicineFile << candidates[i].name << ", " << candidates[i].address << endl;
        }
        else if (candidates[i].course == "pharmacy")
        {
            pharmacyFile << candidates[i].name << ", " << candidates[i].address << endl;
        }
    }

    engineeringFile.close();
    medicineFile.close();
    pharmacyFile.close();

    delete[] candidates;
    return 0;
}
