#include "bits/stdc++.h"
using namespace std;

int main()
{
    ifstream f1("file.txt");
    string s; 
    getline(f1,s);
    
    

    f1.close();
    for(int i = 0 ; i < s.size() ;i++)
    {
        if(s[i] == ' ')
        {
            if(s[i+1] == ' ' && i+1 != s.size())
            {
                int j = i + 1;
                while(j<s.size())
                {
                    s[j] = s[j+1];
                    j++;
                }
            }
        }
    }
    s[s.size()] = '\0';
    

    ofstream f("file.txt");
    f<<s;
    f.close();


}