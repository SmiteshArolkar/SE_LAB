#include "bits/stdc++.h"

using namespace std;
class TeleDir
{
private:
    string name;
    int phone;

public:
    void getUserName()
    {
        cout << "Enter User Name\n";
        cin >> name;
    }
    void getPhoneNumber()
    {
        cout << "Enter New Phone Number\n";
        cin >> phone;
    }

    int registerUser()
    {
        if (1)
        {
            ofstream f("teleDir_data//" + name + ".txt");
            f << phone;
            f.close();
            return 1;
        }
        else
            return 0;
    }

    int searchAndUpdate(string name_s)
    {
        ifstream f1("teleDir_data//" + name_s + ".txt", ios::in);
        if (f1)
        {
            ofstream f("teleDir_data//" + name_s + ".txt");
            cout << "Enter New Phone Number\n";
            int n;
            cin >> n;
            f << n;
            f.close();
            f1.close();
            return 1;
        }
        else
            return 0;
    }
    TeleDir()
    {
    }
};
int main()
{
    TeleDir t;
    int c;
    do
    {
        cout << "1: Register \n2:Search and Update\n0:EXIT\n";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            t.getUserName();
            t.getPhoneNumber();
            if (t.registerUser())
            {
                cout << "Successfully Registered Phone Number\n";
            }
            else
                cout << "Registration Phone Number Unsuccessful\n";
        }
        break;
        case 2:
        {
            string s;
            cout << "Enter User Name\n";
            cin >> s;
            if (t.searchAndUpdate(s))
            {
                cout << "Phone Number Edited Successfully\n";
            }
            else
                cout << "Name does not Exists in dir\n";
        }
        default:
            break;
        }
    } while (c);
}