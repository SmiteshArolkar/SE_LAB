#include <iostream>
using namespace std;

class NUM{
    int x,y;
    void display()
    {
        cout<<"x = "<<x<<" y = "<<y<<endl;
    }
    public:
    NUM(int a,int b)
    {
        x = a;
        y = b;
    }
    ~NUM()
    {
        cout<<"Destructor Call\n";
        display();
    }
   
};

int main()
{
    NUM N1(10,30);

    return 0;
}