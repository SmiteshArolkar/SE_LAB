#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double sum = 0, term;
    cout.setf(ios::showpoint);
    cout << setw(5) << "n" << setw(15) << "Inverse of n" << setw(15) << "Sum of terms\n\n";
    for (int i = 1; i <= 10; i++)
    {
        term = 1.0 / float(i);
        sum = sum + term;
        cout << setw(5) << i << setiosflags(ios::scientific) << setprecision(5) << setw(15) << term << setw(13) << resetiosflags(ios::scientific) << sum << endl;
    }
}