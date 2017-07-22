#include "list.hpp"
#ifndef MENU_HPP
#define MENU_HPP

class Menu {
  private:
    List shoppingList;
  public:
    Menu();
    void displayMenu();
};

#endif