#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // Open the file for reading
    ifstream file("telephone_book.txt");

    // Create an unordered map to store the name-telephone number pairs
    unordered_map<string, string> telephone_book;

    // Read the file line by line
    string name, telephone;
    while (file >> name >> telephone)
    {
        // Insert the name-telephone number pair into the map
        telephone_book[name] = telephone;
    }

    // Close the file
    file.close();
     int choice;
    
    // Display the menu
    do
    {
        cout << "Telephone Book Menu" << endl;
        cout << "1. Determine the telephone number of a person" << endl;
        cout << "2. Determine the name of a person" << endl;
        cout << "3. Update the telephone number of a person" << endl;
        cout << "4. Quit" << endl;

        cin>>choice;
       

        switch (choice)
        {

            // Task 1: Determine the telephone number of a person

        case 1:
            cout << "Enter the name of the person: ";
            cin >> name;

            // Check if the name is in the map
            if (telephone_book.count(name) > 0)
            {
                cout << "Telephone number: " << telephone_book[name] << endl;
            }
            else
            {
                cout << "Name not found in the telephone book\n"
                     << endl;
            }
            break;
        case 2:
        {
            // Task 2: Determine the name of a person
            cout << "Enter the telephone number of the person:\n";
            cin >> telephone;

            // Search the map for the telephone number
            bool found = false;
            for (const auto &entry : telephone_book)
            {
                if (entry.second == telephone)
                {
                    cout << "Name: " << entry.first << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Telephone number not found in the telephone book\n"
                     << endl;
            }
        }
        break;
        case 3:
        {
            // Task 3: Update the telephone number of a person
            cout << "Enter the name of the person: ";
            cin >> name;

            // Check if the name is in the map
            if (telephone_book.count(name) > 0)
            {
                cout << "Enter the new telephone number: ";
                cin >> telephone;
                telephone_book[name] = telephone;
            }
            else
            {
                cout << "Name not found in the telephone book\n"
                     << endl;
            }
        }
        default:
            cout << "Invalid Choice\n";
        }
    }while(choice);

    return 0;
}