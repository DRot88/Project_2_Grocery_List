#include "list.hpp"

List::List() {
  listLength = 4;
  item_array = new Item[listLength];
}

void List::addItem() {

  return;
}

void List::removeItem() {

  return;
}

void List::displayList() {
  for(int x = 0; x < listLength; x++) {
    item_array[x].displayItem();
  }
  return;
}