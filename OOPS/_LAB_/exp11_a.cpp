// Vector Sequence Container
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
void display(vector<int> &);
{
    vector<int> v;

    cout << "\n\nInitial size() = " << v.size();         
    cout << "\n\nInitial capacity() = " << v.capacity(); 
    v.push_back(10); 
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "\n\nAfter push_back() size() = " << v.size();
    cout << "\n\nAfter push_back() capacity() = " << v.capacity();

    cout << "\n\nDisplay vector elements after push_back() :";
    display(v);

    cout << "\n\nFrist element of vector = " << v.front();
    cout << "\n\nLast element of vector = " << v.back();

    vector<int>::iterator itr = v.begin();
    itr = itr + 5;                        
    v.insert(itr, 60);                    

    cout << "\n\nDisplay vector elements after insertion :";
    display(v);


    v.pop_back();

    cout << "\n\nDisplay vector elements after pop_back() :";
    display(v);


    v.erase(v.begin() + 2, v.begin() + 4); 

    cout << "\n\nDisplay vector elements after erase() :";
    display(v);
    v.resize(10);
    cout << "\n\nAfter resize() vector size = " << v.size();
    
    v.clear();

    cout << "\n\nAfter clear() function :";
    display(v);

    cout << "\n\nIs vector empty = " << v.empty();

    getch();
    return 0;
}
void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << v.at(i); 
    }
}