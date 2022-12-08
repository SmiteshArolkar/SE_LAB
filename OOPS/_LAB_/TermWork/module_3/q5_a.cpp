#include "bits/stdc++.h"

using namespace std;


int main()
{
    string s;
    cout<<"Enter a strings\n";
    cin>>s;
    int p = 0;
    for(int i = 0 ; i < (s.size())/2 ; i++)
    {
        if(s[i] != s[s.size()-i-1])
        {
            cout<<"not Pali\n";
            p=1;
            break;
            
        }
    }
    if(!p)
    {
        cout<<"Pali\n";
    }

}