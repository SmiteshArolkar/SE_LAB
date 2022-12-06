#include<iostream>
using namespace std;
void divide(int a,int b)
{  
    try
    {
       if(a==0)
         throw a;
       else
        {float r = b/a;
        cout<<"The Result is "<<r<<endl;
        }  
    }
    catch(int)
    {
        cout<<"Error Divide by Zero in function\n";
        throw;
    }
    
}
int main()
{
    int x,y;
    cout<<"Enter Two Values \n";
    cin>>x>>y;
    try
    {
    divide(x,y);
    divide(x-x,y);
    }
    catch(int)
    {
        cout<<"Error Caught inside Main\n";
    }
}