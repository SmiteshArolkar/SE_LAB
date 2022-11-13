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

class B : virtual public A
{
    int b;

public:
    B()
    {
        b = 0;
    }
    B(int p, int q) : b(p), A(q)
    {
    }
    void DisplayData()
    {
        cout << "B : " << b << "\n";
    }
};

class C : virtual public A
{
    int c;

public:
    C()
    {
        c = 0;
    }
    C(int p, int q) : c(p), A(q)
    {
    }
    void DisplayData()
    {
        cout << "C : " << c << "\n";
    }
};

class D : public B, public C
{
    int d;

public:
    D()
    {
        d = 0;
    }
    D(int p, int q, int r, int s) : d(s), B(q, 0), C(r, 0), A(p)
    {
    }
    void DisplayData()
    {
        cout << "D : " << d << "\n";
    }
};

int main()
{
    D d(10, 20, 30, 40);
    d.A::DisplayData();
    d.B::DisplayData();
    d.C::DisplayData();
    d.DisplayData();
}