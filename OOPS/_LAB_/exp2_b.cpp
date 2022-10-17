#include "iostream"
using namespace std;
class num2;
class num{
    int a;
    public:
    inline void getdata();
    inline void displaydata();
    friend int sum(num &a,num2 &b);

};
inline void num::getdata()
{
    cout<<"Enter data\n";
    cin>>a;
}
inline void num::displaydata()
{
    cout<<"data : "<<a<<"\n sum = ";
}

class num2{
    int a;
    public:
    inline void getdata();
    inline void displaydata();
    friend int sum(num &a,num2 &b);

};

inline void num2::getdata()
{
    cout<<"Enter data\n";
    cin>>a;
}
inline void num2::displaydata()
{
    cout<<"data : "<<a<<"\n";
}
int sum(num &a,num2 &b)
{
    return a.a + b.a;
}
int main()
{
    num n1;
    num2 n2;
    n1.getdata();
    n2.getdata();
    cout<<"Sum of data Using friend Function : "<<sum(n1,n2)<<"\n";

    return 0;
}