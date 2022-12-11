#include "bits/stdc++.h"

using namespace std;


int main()
{
    string s;
    cout<<"Enter a strings\n";
    cin>>s;
    int p = 0;

    vector<char> v1;
    for(int i = s.size()-1 ; i > 0 ; i--)
    {
        v1.push_back(s[i]);
    }
    for(auto i = 0 ; i < v1.size() ; i++)
    {
        if((v1[i] != s[i]))
        p = 1;
        
    }
    if(!p)
    {
        cout<<"Pali\n";
    }
    else cout<<"Not Pali\n";

}