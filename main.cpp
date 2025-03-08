#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart &userCart);
void OutputCart(ShoppingCart &userCart);
void OutputDescriptions(ShoppingCart &userCart);
void RemoveItem(ShoppingCart &userCart);
void ChangeQuantity(ShoppingCart &userCart);

int main()
{
    string customerName;
    string currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    cout << endl;

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;
    cout << endl;

    ShoppingCart cart(customerName, currentDate);

    PrintMenu(cart);
}

void PrintMenu(ShoppingCart &userCart)
{
    char userChoice = ' ';
    bool validChoice;

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
        
        // Reset for new input
        validChoice = false;
        while (!validChoice) {
            cin >> userChoice;
            
            // Check if input was successful and only a single character
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                cout << "Choose a valid option:" << endl;
            } else {
                validChoice = true;
            }
        }
        
        // Clear the newline from the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;

        switch (userChoice) {
            case 'a':
                userCart.AddItem();
                break;
            case 'r':
                RemoveItem(userCart);
                break;
            case 'c':
                ChangeQuantity(userCart);
                break;
            case 'i':
                OutputDescriptions(userCart);
                break;
            case 'o':
                OutputCart(userCart);
                break;
            case 'q':
                // Exit the loop
                break;
            default:
                cout << "Choose a valid option." << endl << endl;
                break;
        }
    }
}

void OutputCart(ShoppingCart &userCart)
{
    cout << "OUTPUT SHOPPING CART" << endl;
    userCart.PrintTotal();
}

void OutputDescriptions(ShoppingCart &userCart)
{
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    userCart.PrintDescriptions();
}

void RemoveItem(ShoppingCart &userCart)
{
    cout << "REMOVE ITEM FROM CART" << endl;
    cout << "Enter name of item to remove:" << endl;
    string itemName;
    getline(cin, itemName);
    cout << endl;
    userCart.RemoveItem(itemName);
}

void ChangeQuantity(ShoppingCart &userCart)
{
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