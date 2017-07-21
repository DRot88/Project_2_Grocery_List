#ifndef LIST_HPP
#define LIST_HPP
#include "item.hpp"
#include <string>
using std::string;

class List {
  private:
    int listLength; // starting length
    Item *item_array;
    Item *temp_array;
    int total;
  public:
    List();
    void addItem();
    void removeItem();
    void displayList();    
    ~List();
};

#endif