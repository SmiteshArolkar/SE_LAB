#include <iostream>
#include <exception>

using namespace std;

void functionA()
{
  cout << "In function A" << endl;
  throw exception(); // throw an exception
}

void functionB()
{
  cout << "In function B" << endl;
  functionA(); // call function A
}

int main()
{
  try
  {
    cout << "In main function" << endl;
    functionB(); // call function B
  }
  catch (exception& e)
  {
    cout << "Exception caught: " << e.what() << endl;
  }
  return 0;
}
