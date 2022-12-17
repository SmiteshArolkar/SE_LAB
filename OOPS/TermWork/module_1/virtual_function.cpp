#include<iostream>
using namespace std;
class base
{
	public:
	virtual void getdata()=0;
	virtual void display()=0;
};
class d1:public base
{
	int x;
	public:
		void getdata()
		{
			cout<<"\nenter X : ";
			cin>>x;
		}
		void display()
		{
			cout<<"VALUE OF X = "<<x;
		}
};
class d2:public base
{
	int y;
	public:
		void getdata()
		{
			cout<<"\nenter Y : ";
			cin>>y;
		}
		void display()
		{
			cout<<"VALUE OF Y = "<<y;
		}
};
int main()
{
 	d1 m;
 	d2 n;
 	base *p;
 	p=&m;
 	cout<<"\n<<==DERIVED CLASS A==>>"<<endl;
 	p->getdata();
 	p->display();
 	p=&n;
 	cout<<"\n\n<<==DERIVED CLASS B==>>"<<endl;
 	p->getdata();
 	p->display();
}