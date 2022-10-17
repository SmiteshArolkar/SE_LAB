#include "iostream"
using namespace std;

void area(int x,int y);//rectangle
void area(float r);//circle

int main()
{
    int c;
    do
    {
        /* code */
        cout<<"1)Area of Rectangle\n2)Area of Circle\n0)exit\n";
        cin>>c;
        switch (c)
        {
        case 1:
        {cout<<"enter l and b\n";
              int x,y;
              cin>>x>>y;
              area(x,y);
        }
            break;
        case 2:cout<<"Enter radius\n";
               float x;
               cin>>x;
               area(x);
               break;
        default:
            break;
        }
    } while (c);
    
}


void area(int x,int y)
{
    cout<<"Area of Rectangle / Square : "<<x*y<<"\n";
}

void area(float r)
{
    cout<<"area of circle : "<<3.14*r*r<<"\n";
}