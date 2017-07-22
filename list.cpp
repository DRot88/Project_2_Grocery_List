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
  listLength = 2;
  item_array = new Item[listLength];
}

List::~List() {
  delete [] item_array;
  item_array = 0;
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
      newItem = 0;
      return;
    } 
  }

  Item *temp_array = new Item[listLength + 1];

  for (int x = 0; x < listLength; x++) {
    temp_array[x] = item_array[x];
  }

  temp_array[listLength] = *newItem;
  delete newItem;
  newItem = 0;

  delete [] item_array;
  item_array = 0;

  item_array = temp_array;

  temp_array = 0;

  listLength += 1;

  return;
}

void List::removeItem() {
  int deletedItemIndex;
  string item_to_remove;
  displayList();

  Item *temp_array = new Item[listLength - 1];

  cout << "Please enter the name of the item you would like to remove: ";
  getline(cin, item_to_remove);

  cout << endl;
  
  for (int x = 0; x < listLength; x++) {
    if (item_to_remove == item_array[x].getName()) {
      deletedItemIndex = x;
    }
  }

  for (int x = 0; x < deletedItemIndex; x++) {
    temp_array[x] = item_array[x];
  }

  for (int x = deletedItemIndex; x < listLength; x++) {
    temp_array[x] = item_array[x+1];
  } 

  delete [] item_array;
  item_array = 0;
  item_array = temp_array;
  temp_array = 0;
  delete [] temp_array;

  listLength -= 1;

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