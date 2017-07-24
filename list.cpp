#include "list.hpp"
#include "item.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//constructor
List::List() {
  listLength = 4;
  item_array = new Item[listLength];
}

//destructor
List::~List() {
  delete [] item_array;
  item_array = 0;
}

/****************************************************************
** Function: addItem
** Description: This will be used to add an item the list. It will
                prompt the user to enter the name, unit, quantity,
                and price of the item. If the item already exists,
                it will inform the user. If it is a new item, it
                will add it to the list, and display the updated
                list.
****************************************************************/
void List::addItem() {
  string itemName = "";
  string itemUnit = "";
  int quant = 0;
  int itemPrice = 0;

  cout << "\nPlease enter the item name you would like to add: ";
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
    if (item_array[x] == *newItem) {
      cout << "The item you are trying to add already exists" << endl << endl;
      delete newItem;
      newItem = 0;
      return;
    } 
  }

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

/****************************************************************
** Function: removeItem
** Description: This will ask the user what item they would like 
                to remove. It will then search the list array
                for the name of that item and remove it by creating
                another array that stores everything except the
                item to be removed.
****************************************************************/
void List::removeItem() {
  int deletedItemIndex;
  string item_to_remove;
  displayList();

  Item *temp_array = new Item[listLength];

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

  for (int x = deletedItemIndex+1; x < listLength; x++) {
    temp_array[x] = item_array[x];
  } 

  delete [] item_array;
  item_array = 0;
  item_array = temp_array;
  temp_array = 0;

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