#include <iostream>
#include <string>
int arr[] = {0,0,0,0,0};

class Student{
  std::string name;
  std::string address;
  std::string branch;
  int roll;
  int generateRoll(std::string branch);
  public:
  	     void getData();
         int searchData(int index);
         void displayData();
         void editData();
         int getRoll(){
         	return roll;
         }
         
};
void Student::getData(){

     std::cout<<"Enter Name : \n";
     std::cin.ignore();
     std::getline(std::cin,name);


     std::cout<<"Enter Address : \n";
     std::getline(std::cin,address);
     std::cout<<"Enter branch [COMP , IT, MECH, CIVIL, ETC]: \n";
     std::getline(std::cin,branch);

     roll = generateRoll(branch);

     //if(s->branch == "COMP") 
     //else if (s->branch == "IT")
     //else if (s->branch == "MECH")
     //else if (s->branch == "CIVIL")
}
int Student::searchData(int index)
{
	if( index == roll) return 1;
	return 0;
}

void Student::displayData(){
	std::cout<<"Name : "<<name<<"\n";
	std::cout<<"Address : "<<address<<"\n";
	std::cout<<"branch : "<<branch<<"\n";
	std::cout<<"Roll : "<<roll<<"\n";
}

void Student::editData(){

	 std::cout<<"Enter Name : \n";
     std::getline(std::cin,name);

     std::cout<<"Enter Address : \n";
     std::getline(std::cin,address);

     std::cout<<"Enter branch : \n";
     std::getline(std::cin,branch);
}
int Student::generateRoll(std::string branch)
{
	if(branch == "COMP") 
	{
		return (1000+arr[0]++);
	}
	else if (branch == "IT")
	{
		return (2000+arr[1]++);
	}
	else if (branch == "MECH")
	{
		return 3000+arr[2]++;
	}
	else if (branch == "CIVIL")
	{
		return 4000+arr[3]++;
		
	}
	else if (branch == "ETC")
	{
		return 5000+arr[4]++;
		
	}
	else return 0;
}

int main(){
	int c,n;
	Student *s;
	do{
		std::cout<<"1)Create 2)Search 3)Edit 4)Display 0)Exit\n";
		std::cin>>c;
		switch(c)
		{
			case 1:
			       std::cout<<"Enter Number of Students\n";
			       std::cin>>n;
				   s = new int[n];
			       for(int i = 0 ; i < n ; i++)
			       {
			       	std::cout<<"Enter Details for Student "<<i+1<<"\n";
			       	s[i].getData();
			       }
			       break;
			case 2:
			{
			       std::cout<<"Enter the roll Number to be Searched\n";
			       int p = 0;
			       int roll;
			       std::cin>>roll;
			       for(int i = 0 ; i < n ;i++)
			       {
			       	if(s[i].searchData(roll)){
			       		p = 1;
			       		break;
			       	}

			       }
			       if(p)std::cout<<"Student Found !\n";
			       else std::cout<<"Student Not Found !\n";
			}
			       break;
			case 3:
			{
			       std::cout<<"Enter Roll Number of Student to Edit Details\n";
			       int roll_1;
			       std::cin>>roll_1;
			       for(int i = 0 ; i < n ; i++)
			       {
			       	if(roll_1 == s[i].getRoll())
			       	{	
			       		s[i].editData();
			       		break;
			       	}

			       }
			}
			       break;
			case 4:std::cout<<"Student Details : \n\n";
                   for(int i = 0 ; i < n ; i++)
                   {
                   	std::cout<<"Student\t"<<i+1<<"\n";
                   	s[i].displayData();
                   }
			       break;
			default:std::cout<<"Invlaid Input\n";
			        break;
		}
	}while(c);
}

