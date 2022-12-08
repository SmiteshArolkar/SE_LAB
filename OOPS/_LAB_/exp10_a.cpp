#include "bits/stdc++.h"
using namespace std;
int main()
{
    vector<int> v1(10,0);

    cout<<"Enter the size of the array\n";
    int size;
    cin>>size;

    v1.resize(size);
    cout<<"Enter Array Elements\n";
    for(vector<int>::iterator  it = v1.begin() ; it != v1.end() ; it++)
    {
        cin>>*it;
    }

    sort(v1.begin(),v1.end());

    cout<<"Sorted Vector Array\n";
    for(vector<int>::iterator  it = v1.begin() ; it != v1.end() ; it++)
    {
        cout<<*it<<"\t";
    }




}