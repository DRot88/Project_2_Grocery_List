#include <iostream>
#include "item.hpp"
#include "list.hpp"
#include "menu.hpp"
using std::cout;
using std::cin;
using std::endl;

int main() {
  Menu groceryMenu;
  cout << "\nWelcome to your Grocery List!" << endl << endl;
  groceryMenu.displayMenu();

  return 0;
}