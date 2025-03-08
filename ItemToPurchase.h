

class ItemToPurchase
{
public:
    ItemToPurchase(string itemName = "none", string itemDescription = "none", int itemPrice = 0, int itemQuantity = 0);
    void SetName(string name);
    string GetName() const;
    void SetDescription(string description);
    string GetDescription() const;
    void SetPrice(int price);
    int GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;

    void PrintItemCost();
    void PrintItemDescription();

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};