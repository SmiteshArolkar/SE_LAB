#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cout<<"Enter a String of len 10\n";
    cin>>s;
    cout<<"Slicing the String [1-5]\n"<<s.substr(1,5)<<"\n";
    cout<<"Searching an Element\n"<<s.find('a')<<"\n";
    cout<<"Capacity of String\n"<<s.capacity()<<"\n";
    string str = "abcde";
    cout<<"Insert New String\n"<<s.insert(6,str)<<"\n";
}