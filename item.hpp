#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;


class Item {
  private:
    string name;
    string unit;
    int quant_to_buy;
    int price;
  public:
    Item();
    Item(string n, string u, int q, int p);
    double extendedPrice();
    void displayItem();
    string getName();
    void setName(string n);
    void setUnit(string u);
    void setQuantToBuy(int q);
    void setPrice(int p);
};

#endif