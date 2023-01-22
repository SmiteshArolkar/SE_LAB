#include <iostream>
#include <fstream>
using namespace std;

class FoodItem
{
public:
    string name;
    float price;
    string manufacturer;
    int quantity;

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main()
{
    FoodItem foodItem;
    fstream file;
    string fileName = "food_items.txt";
    string foodName;
    float lowPrice, highPrice;
    int choice;

    while (1)
    {
        cout << "1. Display food item details when food item name is entered" << endl;
        cout << "2. Display food items between the price range" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            file.open(fileName, ios::in | ios::binary);
            if (!file)
            {
                cout << "Error opening file!" << endl;
                return 1;
            }
            cout << "Enter food item name: ";
            cin >> foodName;
            while (file.read((char *)&foodItem, sizeof(foodItem)))
            {
                if (foodItem.name == foodName)
                {
                    foodItem.display();
                    break;
                }
            }
            file.close();
            break;
        case 2:
            file.open(fileName, ios::in | ios::binary);
            if (!file)
            {
                cout << "Error opening file!" << endl;
                return 1;
            }
            cout << "Enter low price: ";
            cin >> lowPrice;
            cout << "Enter high price: ";
            cin >> highPrice;
            while (file.read((char *)&foodItem, sizeof(foodItem)))
            {
                if (foodItem.price >= lowPrice && foodItem.price <= highPrice)
                {
                    foodItem.display();
                }
            }
            file.close();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}
