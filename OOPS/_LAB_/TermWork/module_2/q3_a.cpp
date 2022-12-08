#include "bits/stdc++.h"
using namespace std;

int main()
{
    ifstream f1("./file.txt");
    string s; 
    while(f1.eof())
    {
       getline(f1,s);
    }
    cout<<s;

}