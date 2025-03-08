

class ItemToPurchase {
    public:
        ItemToPurchase(string name, int price, int quantity);
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