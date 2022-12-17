/*
push_front: Add an element to the front of the list
push_back: Add an element to the back of the list
splice: Move elements from one list to another
sort: Sort the elements of the list in ascending order
merge: Merge two sorted lists into a single sorted list
*/
#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Create an empty list of integers
    list<int> myList;

    // Add some elements to the list using push_front and push_back
    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(4);
    myList.push_back(5);

    // Print the elements of the list
    cout << "Original list: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Create another list and add some elements to it
    list<int> anotherList;
    anotherList.push_back(6);
    anotherList.push_back(7);
    anotherList.push_back(8);

    // Splice the elements from anotherList into myList
    myList.splice(myList.end(), anotherList);

    // Print the elements of the list
    cout << "After splice: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Sort the elements of the list
    myList.sort();

    // Print the elements of the list
    cout << "After sort: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    // Create another list and add some elements to it
    list<int> yetAnotherList;
    yetAnotherList.push_back(9);
    yetAnotherList.push_back(10);
    yetAnotherList.push_back(11);

    // Merge yetAnotherList into myList
    myList.merge(yetAnotherList);

    // Print the elements of the list
    cout << "After merge: ";
    for (int x : myList)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}