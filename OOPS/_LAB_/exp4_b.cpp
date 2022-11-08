#include "iostream"
using namespace std;
class NUM{
    int x;
    public:
    NUM(int a){
        x = a;
    }
    NUM operator -(int p)
    {
        return this->x - p;
    }
    NUM operator *(NUM& a)
    {
        return this->x*a.x;
    }
    NUM operator +(int p)
    {
        return this->x + p;
    }
    operator int()
    {
        return x;
    }
    int getData()
    {
        return x;
    }
};

int main()
{
    NUM x(10),y(20);
    x = 5+y;
    cout<<"x = 5 + y = "<<x.getData()<<"\n";
    x = x*y;
    cout<<"x = x*y = "<<x.getData()<<"\n";
    x = y-5;
    cout<<"x = y -5 = "<<x.getData()<<"\n";

}