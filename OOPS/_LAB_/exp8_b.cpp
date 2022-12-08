#include <iostream>
using namespace std;
void test(int x)
{
    try
    {
        if (x == 1)
            throw x;
        else if (x == -1)
            throw 1.0;
        else if (x == 0)
            throw 'x';
        else
            cout << "No Exception\n";
    }
    catch (char c)
    {
        cout << "Caught a Character\n";
    }
    catch (int c)
    {
        cout << "Caught a Interger\n";
    }
    catch (double c)
    {
        cout << "Caught a Double\n";
    }
}
int main()
{
    cout << "Testing Multiple Catches\n";
    cout << "x=1\n";
    test(1);
    cout << "x=0\n";
    test(0);
    cout << "x=-1\n";
    test(-1);
    cout << "x=2\n";
    test(2);
}