#include "list.hpp"
#include "item.hpp"
#include <iostream>
#include <string>
// #include <memory>
// using std::shared
using std::cout;
using std::cin;
using std::endl;
using std::string;

List::List() {
  listLength = 4;
  item_array = new Item[listLength];
}

List::~List() {
  delete [] temp_array;
  temp_array = NULL;
}

void List::addItem() {
  string itemName = "";
  string itemUnit = "";
  int quant = 0;
  int itemPrice = 0;

  cout << "Please enter the item name you would like to add: ";
  getline(cin, itemName);

  cout << "Please enter the unit you would like to add: ";
  getline(cin, itemUnit);

  cout << "Please enter the quantity you would like to add: ";
  cin >> quant;

  cout << "Please enter the price you would like to add: ";
  cin >> itemPrice; 
  cout << endl;

  Item *newItem = new Item(itemName, itemUnit, quant, itemPrice);
  cin.ignore();

  for (int x = 0; x < listLength; x++) {
    if (item_array[x].getName() == "") {
      item_array[x] = *newItem;
      delete newItem;
      newItem = NULL;
      return;
    } 
  }

  temp_array = new Item[listLength + 1];
  for (int x = 0; x < listLength; x++) {
    temp_array[x] = item_array[x];
  }

  delete [] item_array;
  item_array = NULL;

  temp_array[listLength] = *newItem;
  delete newItem;
  newItem = NULL;

  item_array = temp_array;

  listLength += 1;

  return;
}

void List::removeItem() {

  return;
}

void List::displayList() {
  total = 0;
  for(int x = 0; x < listLength; x++) {
    item_array[x].displayItem();
    total += item_array[x].extendedPrice();
  }

  cout << "\nThe total cost for all of your items in the list is: $" << total << endl << endl;
  return;
}