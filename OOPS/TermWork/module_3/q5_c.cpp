#include "bits/stdc++.h"
/*
Replace With 
#include <string>
#include <algorithm>
#include <iostream>
*/


using namespace std;



int main()
{
    string s;
    cout<<"Enter a String\n";
    getline(cin,s);
    cout<<"Displaying String using Iterator\n";
    for(string::iterator it = s.begin(); it != s.end() ; it++)
    {
        cout<<*it;
    }
}