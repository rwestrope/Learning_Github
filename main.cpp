#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
    string customerName;
    string currentDate;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart cart(customerName, currentDate);
}