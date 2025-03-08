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
void ShoppingCart::RemoveItem(string itemName){
    for (unsigned int i = 0; i < cartItems.size(); i++){
        if (cartItems.at(i).GetName() == itemName){
            cartItems.erase(cartItems.begin() + i);
            return;
        }
        else {
            cout << "Item not found in cart. Nothing removed." << endl;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}
void ShoppingCart::ModifyItem(ItemToPurchase item){
    for (unsigned int i = 0; i < cartItems.size(); i++){
        if (cartItems.at(i).GetName() == item.GetName()){
            if(item.GetDescription() != "none" && item.GetName() != "none"){
                cartItems.at(i).SetName(item.GetName());
                cartItems.at(i).SetDescription(item.GetDescription());
                cartItems.at(i).SetQuantity(item.GetQuantity());
                cartItems.at(i).SetPrice(item.GetPrice());
            }
            return;
        }
        else {
            cout << "Item not found in cart. Nothing modified." << endl;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
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
    for (unsigned int i = 0; i < cartItems.size(); i++){
        cartItems.at(i).PrintItemDescription();
    }
}