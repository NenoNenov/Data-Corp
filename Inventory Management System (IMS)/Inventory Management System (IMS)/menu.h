#ifndef MENU_H
#define MENU_H

#include "inventory.h"

// Class to handle the menu operations
class Menu
{
public:
	Menu(Inventory& inventory);
	void handleMenu();

private:
    Inventory& inventory;

    // Private methods to display and handle menu options
    void displayHeader();
    void displayMenu();
    void addItem();
    void updateItem();
    void deleteItem();
    void searchItemByName();
    void searchItemByID();
    void filterItemsByQuantity();
    void generateReport();
    void printItem(const Item& item);
};


#endif // MENU_H