#include "bits/stdc++.h"
using namespace std;

template<class T>
void swap_number(T &a,T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 10 , b = 20;
    cout<<"A = "<<a<<" B = "<<b<<"\nAfter Swapping\n";
    swap(a,b);
    cout<<"A = "<<a<<" B = "<<b<<"\n";

}
