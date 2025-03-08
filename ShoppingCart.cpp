#include <iostream>
#include <string>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    customerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string customerName, string currentDate){
    this->customerName = customerName;
    this->currentDate = currentDate;
}
string ShoppingCart::GetCustomerName() const{
    return customerName;
}
string ShoppingCart::GetDate() const{
    return currentDate;
}
void ShoppingCart::AddItem(ItemToPurchase item){
    cartItems.push_back(item);
}
void ShoppingCart::AddItem() {
    cout << "ADD ITEM TO CART" << endl;
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter the item name:" << endl;
    string itemName;
    getline(cin, itemName);
    
    cout << "Enter the item description:" << endl;
    string itemDescription;
    getline(cin, itemDescription);
    
    cout << "Enter the item price:" << endl;
    int itemPrice;
    cin >> itemPrice;
    
    cout << "Enter the item quantity:" << endl;
    int itemQuantity;
    cin >> itemQuantity;
    
    // Create and add the item
    ItemToPurchase item(itemName, itemDescription, itemPrice, itemQuantity);
    cartItems.push_back(item);
    
    // Clear input buffer for next input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}
void ShoppingCart::RemoveItem(string itemName){
    bool found = false;
    
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == itemName) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
}
void ShoppingCart::ModifyItem(ItemToPurchase item){
    bool found = false;
    
    for (unsigned int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            if (item.GetQuantity() != 0) {
                cartItems.at(i).SetQuantity(item.GetQuantity());
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}
int ShoppingCart::GetNumItemsInCart() const{
    int totalItems = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++){
        totalItems += cartItems.at(i).GetQuantity();
    }
    return totalItems;
}
int ShoppingCart::GetCostOfCart() const{
    int totalCost = 0;
    for (unsigned int i = 0; i < cartItems.size(); i++){
        totalCost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return totalCost;
}
void ShoppingCart::PrintTotal(){
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    if (cartItems.size() == 0){
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
        for (unsigned int i = 0; i < cartItems.size(); i++){
            cartItems.at(i).PrintItemCost();
        }
        cout << endl << "Total: $" << GetCostOfCart() << endl;
    }
}
void ShoppingCart::PrintDescriptions(){
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
    }
    else {
        for (unsigned int i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintItemDescription();
        }
        cout << endl;
    }
}