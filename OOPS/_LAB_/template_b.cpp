#include "iostream"

using namespace std;

template <class T>
class Vector
{
private:
    T *a;
    int size;

public:
    Vector()
    {
        a = new T;
        size = 0;
    }
    Vector(int size)
    {
        Vector::size = size;
        a = new T[size];
    }
    void input()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
        }
    }

    void resize(int newSize = 0)
    {
        size = newSize;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << "\t";
        }
    }

    int UpdateValue(T element, T newValue)
    {
        int p = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(a[i] == element)
            {
                a[i] = newValue;
                p = 1;
            }
        }

        return p;
    }
};


int main()
{
    Vector<int> v(5);
    v.input();
    v.display();
    v.UpdateValue(1,11);
    cout<<"\n";
    v.display();
}
