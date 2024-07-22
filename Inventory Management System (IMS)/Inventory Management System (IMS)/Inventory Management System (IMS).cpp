#include <iostream>
#include "inventory.h"
#include "menu.h"


int main() {
    Inventory inventory; // Create an inventory object

    inventory.addItem("Item1", 100, 10.5, "Supplier1");
    inventory.addItem("Item2", 200, 20.0, "Supplier2");

    Menu menu(inventory);
    menu.handleMenu();

    return 0;
}
