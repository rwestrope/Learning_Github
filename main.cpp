#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart userCart) {
    char userChoice;

    while (userChoice != 'q') {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "r - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl;
        cout << endl;

        cout << "Choose an option:" << endl;
        cout << endl;
        cin >> userChoice;
        if (userChoice != 'a' && userChoice != 'r' && userChoice != 'c' && userChoice != 'i' && userChoice != 'o' && userChoice != 'q') {
            cout << "Choose a valid option." << endl;
            cin >> userChoice;
            cout << endl;
        }
        else if (userChoice == 'a') {
            AddItem(userCart);
        }
        else if (userChoice == 'r') {
            RemoveItem(userCart);
        }
        else if (userChoice == 'c') {
            ChangeQuantity(userCart);
        }
        else if (userChoice == 'i') {
            OutputDescriptions(userCart);
        }
        else if (userChoice == 'o') {
            OutputCart(userCart);
        }
        else if (userChoice == 'q') {
            break;
        }
    }
}
void OutputCart (ShoppingCart userCart) {
    cout << "OUTPUT SHOPPING CART" << endl;
    userCart.PrintTotal();
}
void OutputDescriptions(ShoppingCart userCart) {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    userCart.PrintDescriptions();
}
void AddItem(ShoppingCart userCart) {
    cout << "ADD ITEM TO CART" << endl;
    cout << "Enter the item name:" << endl;
    string itemName;
    getline(cin, itemName);
    cout << endl;
    cout << "Enter the item description:" << endl;
    string itemDescription;
    getline(cin, itemDescription);
    cout << endl;
    cout << "Enter the item price:" << endl;
    int itemPrice;
    cin >> itemPrice;
    cout << endl;
    cout << "Enter the item quantity:" << endl;
    int itemQuantity;
    cin >> itemQuantity;
    cout << endl;
    ItemToPurchase item(itemName, itemDescription, itemPrice, itemQuantity);
    userCart.AddItem(item);
}
void RemoveItem(ShoppingCart userCart) {
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter the name of item to remove:" << endl;
    string itemName;
    getline(cin, itemName);
    userCart.RemoveItem(itemName);
}
void ChangeQuantity(ShoppingCart userCart) {
    cout << "CHANGE ITEM QUANTITY" << endl;
    cout << "Enter the item name:" << endl;
    string itemName;
    getline(cin, itemName);
    cout << endl;
    cout << "Enter the new quantity:" << endl;
    int itemQuantity;
    cin >> itemQuantity;
    ItemToPurchase item(itemName, "none", 0, itemQuantity);
    userCart.ModifyItem(item);
}

int main() {
    string customerName;
    string currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    cout << endl;

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart cart(customerName, currentDate);
}