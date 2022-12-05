#include <iostream>
#include <string.h>
using namespace std;

class string1
{
    char str[30];

public:
    string1()
    {
        strcpy(str, "");
    }
    string1(char *s)
    {
        strcpy(str, s);
    }
    string1 operator +(string1 &s)
    {
        string1 s1;
        char temp[30];
        strcpy(temp,str);
        strcpy(s1.str, strcat(str, s.str));
        strcpy(str,temp);
        return s1;
    }
    void display()
    {
        cout << str << endl;
    }

    int operator >(string1 &s)
    {
        if (strcmp(this->str, s.str) == 0)
        {
            return 0;
        }
        else if (strcmp(str, s.str) >= 1)
        {
            return 1;
        }
        else
            return -1;
    }
};
int main()
{
    string1 s1;
    char a[20] = "Hello";
    char b[20] = "World";
    string1 s2(a);
    s2.display();
    string1 s3(b);
    s3.display();
    s1 = s2 + s3;
    cout<<"After adding s2 and s3\n";
    s1.display();


       
    if (s1 > s2)
        cout << "\nS2 is smaller than s1" << endl;
    if (s2 > s3)
        cout << "\nS3 is smaller than s1" << endl;
    return 0;
}
