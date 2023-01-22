#include<iostream>
using namespace std;
template<class t>
class vector
{
    t* v;
    int size;
    public:
    void getdata();
    friend vector<t> operator +(int a, vector<t> &y);
    void display();
};
template<class t>
void vector<t>::getdata()
{
    cout<<"Enter the size of the vector\n";
    cin>>size;
    v = new t[size];
    cout<<"Enter the vector elements\n";
    for(int i=0 ; i<size ;i++)
    cin>>v[i];
}

template<class t>
vector<t> operator+(int a, vector<t> &y)
{
    vector<t> ans;
    ans=new int[size];
    for(int i=0;i<size;i++)
    {
         ans.v[i] = a + y.v[i];
    }
    return ans;
}

template<class t>
void vector<t>::display()
{
        for(int i=0 ; i<size ; i++)
            cout<<v[i]<<" ";
        cout<<endl;
}

int main()
{
    vector<int>v1;
    vector<float>v2;
    v1.getdata();
    v2.getdata();
    cout<<"Vector 1:\n";
    v1.display();
    cout<<"Vector 2:\n";
    v2.display();
    v1 = 5 + v2;
    cout<<"Added vector\n";
    v1.display();
}