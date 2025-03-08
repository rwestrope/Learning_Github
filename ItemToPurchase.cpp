#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

string ItemToPurchase::GetName() const {
    return itemName;
}
void ItemToPurchase::SetName(string name) {
    itemName = name;
}
string ItemToPurchase::GetDescription() const {
    return itemDescription;
}
void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}
int ItemToPurchase::GetPrice() const {
    return itemPrice;
}
void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}
void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}