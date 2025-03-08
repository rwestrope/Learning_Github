#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart& userCart);
void OutputCart(ShoppingCart& userCart);
void OutputDescriptions(ShoppingCart& userCart);
void RemoveItem(ShoppingCart& userCart);
void ChangeQuantity(ShoppingCart& userCart);

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

void PrintMenu(ShoppingCart& userCart) {
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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin >> userChoice;

        if (userChoice == 'a') {
            userCart.AddItem();
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
        else {
            cout << "Choose a valid option." << endl << endl;
        }
    }
}

void OutputCart(ShoppingCart& userCart) {
    cout << "OUTPUT SHOPPING CART" << endl;
    userCart.PrintTotal();
}

void OutputDescriptions(ShoppingCart& userCart) {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    userCart.PrintDescriptions();
}

void RemoveItem(ShoppingCart& userCart) {
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter name of item to remove:" << endl;
    string itemName;
    getline(cin, itemName);
    cout << endl;
    userCart.RemoveItem(itemName);
}

void ChangeQuantity(ShoppingCart& userCart) {
    cout << "CHANGE ITEM QUANTITY" << endl;
    cout << "Enter the item name:" << endl;
    string itemName;
    getline(cin, itemName);
    
    cout << "Enter the new quantity:" << endl;
    int itemQuantity;
    cin >> itemQuantity;
    cout << endl;
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    ItemToPurchase item(itemName, "none", 0, itemQuantity);
    userCart.ModifyItem(item);
}