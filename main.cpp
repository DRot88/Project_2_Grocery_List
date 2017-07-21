#include <iostream>
#include "item.hpp"
#include "list.hpp"
using std::cout;
using std::cin;
using std::endl;

int main() {

  cout << "\nWelcome to your shopping list!" << endl << endl;

  List shoppingList;
  Item item1("Cheese", "Boxes", 3, 4);

  item1.displayItem();
  shoppingList.displayList();

  return 0;
}