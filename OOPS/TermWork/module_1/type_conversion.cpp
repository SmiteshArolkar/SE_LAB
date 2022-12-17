#include<iostream>
#include<math.h>
using namespace std;
class cart
{
	float x;
	float y;
	public:
	void getcart();	
	float getx(){return x;}
	float gety(){return y;}
	void display()
	{
		cout<<"X = "<<x<<endl<<"Y = "<<y<<endl;
	}
};
class polar
{
	float a;
	float r;
	public:
	polar(){a=0;r=0;}
	polar(cart &);
	void display()
	{
		cout<<"R = "<<r<<"\nA = "<<a;
	}
};
void cart::getcart()
{
	cout<<"enter X : ";
	cin>>x;
	cout<<"enter Y : ";
	cin>>y;
}
polar::polar(cart &cartesian)
{
	float x;
	float y;
	x=cartesian.getx();
	y=cartesian.gety();
	if(x==0)
	a=(11.0/7);
	else
	a=atan(y/x);
	r=sqrt(x*x + y*y);
}
using namespace std;
int main()
{
	cart m;
	m.getcart();
	polar n;
	n=m;
	cout<<"<<== CARTESIAN FORM ==>>\n";
	m.display();
	cout<<"<<== POLAR FORM ==>>\n";
	n.display();
	return 0;
}