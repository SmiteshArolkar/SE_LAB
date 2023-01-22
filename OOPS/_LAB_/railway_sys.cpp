#include <fstream>
#include "iostream"
#include "string"

using namespace std;

class Rail
{

public:
    string p_name;
    int age;
    string st_place, end_dest;
    int reg_id;
    string c_type;

    void get_data()
    {
        cout << "Name age st_place end_dest coach_type reg_id\n";
        cin >> p_name >> age >> st_place >> end_dest >> c_type >> reg_id;
        store_data();
    }

    void display_data(string c_type_key)
    {
        ifstream f(c_type_key);
        while (!f.eof())
        {
            Rail temp;
            f.read((char *)&temp, sizeof(Rail));
            cout<<"\nName : "<<temp.p_name;
            cout<<"Age : " <<temp.age;
        }
        f.close();
    }

    void display_data_id(int id)
    {
        ifstream f("Rail.txt");
        while(!f.eof())
        {
            Rail temp;
            f.read((char*)&temp,sizeof(Rail));
            if(temp.reg_id == id)
            {
                cout<<"Name : "<<temp.p_name<<"\n";
            }
        }
        f.close();
        
    }

    void store_data()
    {
        ofstream f("2A.txt",ios::ate) , f2("3A.txt",ios::ate) , f3("SL.txt",ios::ate) , f4("Rail.txt",ios::ate);
        if(this->c_type == "2A")
        {
            f.write((char*)this,sizeof(Rail));
        }
        else if(this->c_type == "3A")
        {
            f2.write((char*)this,sizeof(Rail));
        }
        else
        {
            f3.write((char*)this,sizeof(Rail));
        }

        f4.write((char*)this,sizeof(Rail));

        f.close();
        f4.close();
        f2.close();
        f3.close();
    }
};

int main()
{
   
    int n;
    cout<<"Enter Number of Records\n";
    cin>>n;
    Rail rail[100];

    for(int i = 0 ; i < n ; i ++)
    {
        rail[i].get_data();
    }

    cout<<"Enter reg_id\n";
    int id;
    cin>>id;

    rail[0].display_data_id(id);

}