

class ItemToPurchase {
    public:
        ItemToPurchase(string itemName = "none", int itemPrice = 0, int itemQuantity = 0);
        void SetName(string name);
        string GetName() const;
        void SetPrice(int price);
        int GetPrice() const;
        void SetQuantity(int quantity);
        int GetQuantity() const;
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
};