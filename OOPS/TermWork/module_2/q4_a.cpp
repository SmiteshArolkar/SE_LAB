#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    try{
        if(n > 9999)
        {
            throw n;
        }
        else cout<<"No exception\n";

    }
    catch(int n)
    {
        cout<<"Number Greater than 9999 : \n"<<n;
    }
}