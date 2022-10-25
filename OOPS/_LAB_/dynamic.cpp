#include "iostream"
using namespace std;

class dynamic{
    const char *a;
    int *b;
    public:
    dynamic()
    {
        a = new char[6];
        a = "Hello";
        b = new int[10];
    }
    void display()
    {
        cout<<a<<"\n";
    }
};

int main()
{
    dynamic a;
    a.display();
    return 0;
}