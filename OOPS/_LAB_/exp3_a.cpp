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
    void display()
    {
        cout<<"x = "<<x<<" y = "<<y<<endl;
    }

};


int main()
{
    NUM N1(10,20);
    N1.display();
    return 0;
}