#include <iostream>
#include <fstream>

int main() {
  std::ifstream input("input.txt");  // Open the input file for reading
  std::ofstream output("output.txt");  // Open the output file for writing

  // Read the input file one character at a time
  char c;
  while (input.get(c)) {
    // If the character is a space, skip all consecutive spaces
    if (c == ' ') {
      while (input.peek() == ' ') {
        input.get(c);
      }
    }
    // Write the character to the output file
    output << c;
  }

  // Close the input and output files
  input.close();
  output.close();

  return 0;
}