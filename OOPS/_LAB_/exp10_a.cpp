#include "bits/stdc++.h"

using namespace std;

int main()
{
    ofstream f1("file1.txt");
    cout << "Enter 5 Elements\n";
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        f1 << n;
    }
    f1.close();
    f1.open("file2.txt", ios::out);
    cout << "Enter 3 Elements\n";
    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        f1 << n;
    }

    f1.close();

    ifstream f("file1.txt");

    vector<int> v1;

    while (f.good())
    {
        int n;
        char c;
        f.get(c);
        n = (int)c - 48;
        v1.push_back(n);
    }
    v1.pop_back();

    f.close();

    f.open("file2.txt");

    while (f.good())
    {
        int n;
        char c;
        f.get(c);
        n = (int)c - 48;
        v1.push_back(n);
    }
    v1.pop_back();
    f.close();

    f1.open("file3.txt", ios::out);

    sort(v1.begin(), v1.end());

    for (int i = 0; i < 8; i++)
    {
        f1 << v1[i];
    }

    cout << "Contents of file 3\n";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << "\t";
    }
}
