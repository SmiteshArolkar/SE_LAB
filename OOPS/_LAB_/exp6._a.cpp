#include "iostream"

using namespace std;

class Base
{
    public:
    virtual void print()
    {
        cout<<"Printing Base Class\n";
    } 
    void show()
    {
        cout<<"Showing Base Class\n";
    }
};

class Derived : public Base
{
    public:
    void print()
    {
        cout<<"Printing Derived Class\n";
    }
    void show()
    {
        cout<<"Showing Derived Class\n";
    }
};

int main()
{
    
    Derived derived;
    Base* base = &derived;

    base->print();
    base->show();

}