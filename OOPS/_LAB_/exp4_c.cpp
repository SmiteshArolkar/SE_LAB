#include "iostream"
using namespace std;
class num{
    int n;
    public:
    num(int a){
        n = a;
    }
    friend void operator >>(istream &a,num& b)
    {
        a>>b.n;
    }

    friend void operator <<(ostream &a,num &b)
    {
        a<<b.n;
    }
};

int main()
{
    num a(10);
    cin>>a;
    cout<<a;
}