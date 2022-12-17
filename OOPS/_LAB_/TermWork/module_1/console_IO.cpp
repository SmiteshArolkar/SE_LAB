#include <iostream>
#include <iomanip>
using namespace std;
class manip
{
	float price;
	int code;
	char name[30];

public:
	void getdata();
	void putdata();
};
void manip::getdata()
{
	getchar();
	cout << "\n\n<<USER DETAILS>>\n";
	cout << "enter name : ";
	cin.getline(name, 30);
	cout << "enter code : ";
	cin >> code;
	cout << "enter price : ";
	cin >> price;
}
void manip::putdata()
{
	cout.setf(ios::left, ios::adjustfield);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout.fill(' ');
	cout.width(25);
	cout << name;
	cout.width(15);
	cout << code;
	cout.width(15);
	cout << price << endl;
}
int main()
{
	int n;
	cout << "enter the number of datails to be stored : ";
	cin >> n;
	manip *a;
	a = new manip[n];
	for (int i = 0; i < n; i++)
		a[i].getdata();
	cout.fill('-');
	cout.width(50);
	cout.setf(ios::left, ios::adjustfield);
	cout << "" << endl;
	cout.fill(' ');
	cout.width(25);
	cout << "Name";
	cout.width(15);
	cout << "Code";
	cout.width(15);
	cout << "Price" << endl;
	cout.fill('-');
	cout.width(50);
	cout << "";
	cout.fill(' ');
	cout << endl;
	for (int i = 0; i < n; i++)
		a[i].putdata();
	return 0;
}
