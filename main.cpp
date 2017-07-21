#include <iostream>
#include "item.hpp"
#include "list.hpp"
using std::cout;
using std::cin;
using std::endl;

int main() {

  cout << "\nWelcome to your shopping list!" << endl << endl;

  List shoppingList;
  shoppingList.displayList();
  shoppingList.addItem();
  shoppingList.displayList();
  shoppingList.addItem();
  shoppingList.displayList();
  shoppingList.addItem();
  shoppingList.displayList();
  shoppingList.removeItem();
  shoppingList.displayList();


  return 0;
}