#include <iostream>
using namespace std;

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include <limits>
#include "ItemToPurchase.h"

class ShoppingCart{
    public:
        ShoppingCart();
        ShoppingCart(string customerName, string currentDate);
        string GetCustomerName() const;
        string GetDate() const;
        void AddItem(ItemToPurchase item);
        void AddItem();
        void RemoveItem(string itemName);
        void ModifyItem(ItemToPurchase item);
        int GetNumItemsInCart() const;
        int GetCostOfCart() const;
        void PrintTotal();
        void PrintDescriptions();
    private:
        string customerName;
        string currentDate;
        vector<ItemToPurchase> cartItems;
};

#endif // SHOPPING_CART_H