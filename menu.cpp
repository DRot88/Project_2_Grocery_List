#include "menu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Menu::Menu() {
  return;
}

/****************************************************************
** Function: displayMenu
** Description: This will display the options for the user to 
                use for the grocery list.
****************************************************************/

void Menu::displayMenu() {
  int choice;
  cout << "1: Print Current List" << endl;
  cout << "2: Add Items To List" << endl;
  cout << "3: Remove Items From List" << endl;
  cout << "4: Exit" << endl << endl;
  cout << "Please choose from one of the above options: ";
  cin >> choice;

  switch(choice) {
    case 1 :
      cin.ignore();
      cout << "\nBelow is your grocery list: " << endl << endl;
      shoppingList.displayList();
      displayMenu();
      break;
    case 2 :
      cin.ignore();
      shoppingList.addItem();
      shoppingList.displayList();
      displayMenu();
      break;
    case 3 :
      cin.ignore();
      shoppingList.removeItem();
      shoppingList.displayList();
      displayMenu();
      break;
    case 4 :
      cin.ignore();
      cout << "Exiting the program." << endl << endl;
      break;
    default :
      cout << "Invalid choice, exiting the program." << endl << endl;
  }

}