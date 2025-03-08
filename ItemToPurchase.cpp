#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

string ItemToPurchase::GetName() const {
    return itemName;
}
void ItemToPurchase::SetName(string name) {
    itemName = name;
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