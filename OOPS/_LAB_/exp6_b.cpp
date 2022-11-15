#include "iostream"
using namespace std;


class Base
{
    
    public:
    int a;
    Base(int p):a(p){

    }
    Base()
    {
        a = 0;
    }
    virtual void func() = 0;
    void display()
    {
        cout<<"BASE A = "<<a<<"\n";
    }
};

class Derived : public Base
{
    public:
    Derived(int p): Base(p)
    {

    }
    Derived()
    {

    }

    void func()
    {
        a++;
    }

    void display()
    {
        cout<<"DERIVED A = "<<a<<"\n";
    }
};
int main()
{
    Derived a(10);
    a.display();
    a.Base::display();
    
    a.func();

    cout<<"After calling Pure virtual Function \n";
    a.display();
}