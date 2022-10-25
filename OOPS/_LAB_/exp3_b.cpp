#include <iostream>
using namespace std;

class NUM{

    int x;
    int y;
    
    public: 

    NUM(int a,int b)
    {
        x = a;
        y = b;
    }

    NUM(NUM &a)//copy constructor
    {
        x = a.x;
        y = a.y;
    }
    void display()
    {
        cout<<"x = "<<x<<" y = "<<y<<endl;
    }

};


int main()
{
    NUM N1(10,20);
    NUM N2(N1);
    cout<<"# ";
    N2.display();
    return 0;
}