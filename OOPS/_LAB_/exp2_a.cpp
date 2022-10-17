#include "iostream"
using namespace std;

void add(int &a,int &b,int &result)
{
    result = a + b;
}


int main()
{
    int a = 10 , b = 20 , c = 0;
    cout<<"Before Adding Value of c : "<<c<<"\n";
    add(a,b,c);
    cout<<"After adding a + b = c : "<<c<<"\n";
    return 0;
}

// O/P: Before Adding Value of c : 0
//    After adding a + b = c : 30