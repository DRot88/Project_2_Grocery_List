#include "item.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

Item::Item() {
  name = "";
  unit = "";
  quant_to_buy = 0;
  price = 0;
}

Item::Item(string n, string u, int q, int p) {
  name = n;
  unit = u;
  quant_to_buy = q;
  price = p;
}

void Item::displayItem() {
  cout << "Item: " << this->name << endl;
  cout << "Price: " << "$" << this->price << endl;
  cout << "Unit: " << this->unit << endl;
  cout << "Quantity: " << this->quant_to_buy << endl;
  cout << "Extended Price: " << "$" << this->extendedPrice() << endl << endl;
  return;
}

double Item::extendedPrice() {
  return (this->price * this->quant_to_buy);
}

string Item::getName() {
  return name;
}

void Item::setName(string n) {
  name = n;
}

void Item::setUnit(string u) {
  unit = u;
}

void Item::setQuantToBuy(int q) {
  quant_to_buy = q;
}

void Item::setPrice(int p) {
  price = p;
}

/****************************************************************
** Function: operator==
** Description: This will overload to == operator to help test
                if an item already exists in the list.
****************************************************************/

bool Item::operator==(Item& right) {
  if (this->name==right.name){
    return true;
  }
  return false;
}
