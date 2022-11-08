//operator overloading
#include "iostream"
using namespace std;
class num{
    int n;
    public:num(int p) {
        n = p;
    }
    void display(){
        cout<<n<<"\n";
    }
    void operator ++()
    {
        n = n + 1;
    }

    void operator --()
    {
        n = n -1 ;
    }
    void operator ++(int)
    {
        n = n + 1;
    }

    void operator --(int)
    {
        n = n - 1;
    }
};
int  main()
{
    num n(10);
    cout<<"Before Increment = ";
    n.display();
    n++;
    cout<<"After Increment = ";
    n.display();
    cout<<"Before Decrement = ";
    n.display();
    n--;
    cout<<"After Decrement = ";
    n.display();

}