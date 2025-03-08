#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"

int main() {
    string item1Name;
    int item1Price;
    int item1Quantity;
    string item2Name;
    int item2Price;
    int item2Quantity;

    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, item1Name);

    cout << "Enter the item price:" << endl;
    cin >> item1Price;

    cout << "Enter the item quantity:" << endl;
    cin >> item1Quantity;

    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, item2Name);

    cout << "Enter the item price:" << endl;
    cin >> item2Price;

    cout << "Enter the item quantity:" << endl;
    cin >> item2Quantity;


    cout << "TOTAL COST" << endl;
    ItemToPurchase item1(item1Name, item1Price, item1Quantity);
    ItemToPurchase item2(item2Name, item2Price, item2Quantity);

    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << endl;

    cout << endl;
    cout << "Total: $" << (item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity()) << endl;
}