#include<iostream>
#include<string.h>
using namespace std;
int main()
{ char a[20];
  int b,c=0;
  cout<<"Enter the Text"<<endl;
  cin.getline(a,20);
  cout.setf(ios::left,ios::adjustfield);
  cout.width(20);
  cout<<"Number  of  Lines";
  cout.width(20);
  cout<<"Number  of  words";
  cout.width(25);
  cout<<"Number  of  characters"<<endl;
  cout.setf(ios::right,ios::adjustfield);
  cout.width(10);
  cout<<"1";
  b=strlen(a);
  for(int i=0;i<b;i++)
  {
      if(a[i]==' ')
         c++; 
  }
  cout.width(15);
  cout<<c+1;
  cout.width(20);
  cout<<b;
}