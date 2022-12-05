#include "iostream"
#include "iomanip"
#include "vector"
using namespace std;

void printArray(char a[], int size)
{
    char b[6];
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << left;
    }
}

int main()
{

    char arr1[] = "object";

    for (int i = 0, w_string = 6, witdh = 1; i < 6; i++, arr1[w_string] = '\0', w_string--, witdh = witdh + 2)
    {
        int j = 0;
        for (j = 0; j < w_string; j++)
        {
            cout << arr1[j];
        }

        cout.width(witdh);
        cout << right;

        for (int k = j - 1; k >= 0; k--)
        {
            cout << arr1[k];
        }

        if (i == 4)
        {
            cout.fill('*');
        }
        if (i == 5)
        {
            cout.fill(' ');
        }
        cout << endl;
    }
    char arr[] = "object";
    for (int i = 0, width = 9; i < 5; i++, width = width - 2)
    {
        int j = 0;
        for (j = 0; j <= i + 1; j++)
        {
            cout << arr[j];
        }
        cout.width(width);
        cout << right;

        for (int k = j - 1; k >= 0; k--)
        {
            cout << arr[k] << left;
        }
        cout << endl;
    }
}