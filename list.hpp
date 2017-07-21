#ifndef LIST_HPP
#define LIST_HPP
#include "item.hpp"

class List {
  private:
    int listLength; // starting length
    Item *item_array;
  public:
    List();
    void addItem();
    void removeItem();
    void displayList();    
};

#endif