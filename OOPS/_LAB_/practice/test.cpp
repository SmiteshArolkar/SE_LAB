#include "iostream"
#include "fstream"
#include "string"
using namespace std;

class Candidates
{
public:
    string name;
    string address;
    string course;

public:
    Candidates()
    {
    }
    Candidates(string c_name, string c_address, string c_course) : name(c_name), address(c_address), course(c_course) {}
    string getCourse()
    {
        return course;
    }
    void display()
    {

        cout << "Calling display" << name << "\t" << address << "\t" << course << "\n";
    }
};

int main()
{
    int n;
    cout << "Enter Number of candidates\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name, add, course;
        fflush(stdin);
        cout << "Enter Candidate Name\n";
        getline(cin, name);
        cout << "Enter Candidate add\n";
        getline(cin, add);
        cout << "Enter Candidate Course\n";
        getline(cin, course);
        Candidates c(name, add, course);
        ofstream file;
        if (c.getCourse() == "ENG")
        {
            file.open("ENG.txt", ios::app | ios::out);
            if (file.good())
            {
                file << c.name << "," << c.address << "," << c.course << endl;
            }
            file.close();
        }
        else if (c.getCourse() == "MED")
        {
            file.open("MED.txt", ios::ate | ios::out);
            if (file.good())
            {
                file << c.name << "," << c.address << "," << c.course << endl;
            }
            file.close();
        }
        else if (c.getCourse() == "PHY")
        {
            file.open("PHY.txt", ios::ate | ios::out);
            if (file.good())
            {
                file << c.name << "," << c.address << "," << c.course << endl;
            }
            file.close();
        }
    }

    ifstream file("ENG.txt", ios::in);
    Candidates c;
    while (!file.eof())
    {

        string name, add, course;
        file >> name >> add >> course;
        cout << name << add << course << endl;
    }

    file.close();
}