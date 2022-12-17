#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  // Read the string from the user
  cout << "Enter a string: ";
  string str;
  
  getline(cin, str);

  string s(str);


  // Reverse the string
  reverse(str.begin(), str.end());

  // Check if the string is a palindrome
  if (str == s) {
    cout << "The string is a palindrome." << endl;
  } else {
    cout << "The string is not a palindrome." << endl;
  }

  return 0;
}