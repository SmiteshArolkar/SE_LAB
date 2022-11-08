#include "iostream"
using namespace std;

class Vector{
    int* a;
    int n;
    public:
    Vector(int size,int value)
    {
        n = size;
        a = new int[size];
        for(int i = 0 ; i < size ; i++)
        {
            a[i] = value;
        }
    }

    Vector operator + (Vector &a)
    {
        Vector b(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            b.a[i] = this->a[i] + a.a[i];
        }

        return b;
    }
    void display()
    {
        for(int i = 0 ; i < n ; i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<"\n";
    }
};

int main()
{
    Vector a(5,1);
    Vector b(5,2);

    Vector c = a+b;
    c.display();

}