#include "iostream"
using namespace std;

class A
{
    int a;

public:
    A()
    {
        a = 0;
    }
    A(int p) : a(p)
    {
    }
    void DisplayData()
    {
        cout << "A : " << a << "\n";
    }
};

class B : public A
{
    int b;
    public: B(){
        b = 0;
    }
    B(int p,int q):A(p),b(q)
    {
        cout<<"in Class B B =  "<<b<<"\n";
        A::DisplayData();
    }
     void DisplayData()
    {
        cout << "B : " << b << "\n";
    }
};

class C : public A
{
     int c;
    public: C(){
        c = 0;
    }
    C(int p,int q):A(p),c(q)
    {
        cout<<"in Class C C =  "<<c<<"\n";
        A::DisplayData();
    }
     void DisplayData()
    {
        cout << "B : " << c << "\n";
    }
};

int main()
{
    B b(10,20);
    C c(30,40);
}