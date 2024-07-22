#include "menu.h"
#include "validator.h"
#include "utils.h"
#include <iostream>
#include <limits>

Menu::Menu(Inventory& inventory) : inventory(inventory) {}

//Display the header of the menu
void Menu::displayHeader() {
    clearConsole();
    std::cout << "===========================\n";
    std::cout << " Inventory Management System (IMS) \n";
    std::cout << "===========================\n";
}

//Display the menu options
void Menu::displayMenu() {
    std::cout << "1. Add Item\n";
    std::cout << "2. Update Item\n";
    std::cout << "3. Delete Item\n";
    std::cout << "4. Search Item by Name\n";
    std::cout << "5. Search Item by ID\n";
    std::cout << "6. Filter Items by Quantity\n";
    std::cout << "7. Generate Report\n";
    std::cout << "8. Exit\n";
    std::cout << "===========================\n";
    std::cout << "Enter your choice: ";
}


//Main method to handle the menu and user input
void Menu::handleMenu() {
    int choice;
    while (true) {
        displayHeader();
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            displayHeader();
            addItem();
            break;
        case 2:
            displayHeader();
            updateItem();
            break;
        case 3:
            displayHeader();
            deleteItem();
            break;
        case 4:
            displayHeader();
            searchItemByName();
            break;
        case 5:
            displayHeader();
            searchItemByID();
            break;
        case 6:
            displayHeader();
            filterItemsByQuantity();
            break;
        case 7:
            displayHeader();
            generateReport();
            break;
        case 8:
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        //Pause and wait for user to press Enter before continuing
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

// Method to add an item to the inventory
void Menu::addItem()
{
    std::string name, supplier;
    int quantity;
    double price;

    while (true)
    {
        std::cout << "Enter item name (3-50 characters): ";
        std::cin >> name;
        if (!Validator::validateString(name, 3, 50)) {
            std::cout << "Invalid name length. Try again.\n";
        }
        else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        if (std::cin.fail() || !Validator::validateQuantity(quantity)) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input buffer
            std::cout << "Quantity must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter price: ";
        std::cin >> price;
        if (std::cin.fail() || !Validator::validatePrice(price)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Price must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter supplier (3-50 characters): ";
        std::cin >> supplier;
        if (!Validator::validateString(supplier, 3, 50)) {
            std::cout << "Invalid supplier length. Try again.\n";
        }
        else {
            break;
        }
    }

    inventory.addItem(name, quantity, price, supplier);
    std::cout << "Item added successfully!\n";
}

// Method to update an item in the inventory
void Menu::updateItem()
{
    int id, quantity;
    double price;
    std::string supplier;

    // Input item ID with validation
    while (true) {
        std::cout << "Enter item ID to update: ";
        std::cin >> id;
        if (std::cin.fail() || id <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ID must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    // Input new item details with validation
    while (true) {
        std::cout << "Enter new quantity: ";
        std::cin >> quantity;
        if (std::cin.fail() || !Validator::validateQuantity(quantity)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Quantity must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter new price: ";
        std::cin >> price;
        if (std::cin.fail() || !Validator::validatePrice(price)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Price must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter new supplier (3-50 characters): ";
        std::cin >> supplier;
        if (!Validator::validateString(supplier, 3, 50)) {
            std::cout << "Invalid supplier length. Try again.\n";
        }
        else {
            break;
        }
    }

    inventory.updateItem(id, quantity, price, supplier);
    std::cout << "Item updated successfully!\n";
}

// Method to delete an item from the inventory
void Menu::deleteItem()
{
    int id;

    while (true)
    {
        std::cout << "Enter item ID to delete: ";
        std::cin >> id;
        if (std::cin.fail() || id <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ID must be a positive number. Try again.\n";
        }
        else
        {
            break;
        }
    }
    inventory.deleteItem(id);
    std::cout << "Item deleted successfully!\n";
}

// Method to search for items by name
void Menu::searchItemByName()
{
    std::string name;

    while (true)
    {
        std::cout << "Enter item name to search (3-50 characters): ";
        std::cin >> name;
        if (!Validator::validateString(name, 3, 50)) {
            std::cout << "Invalid name length. Try again.\n";
        }
        else {
            break;
        }
    }

    auto results = inventory.searchItemByName(name);
    for(const auto& item : results )
    {
        printItem(item);
    }
}

// Method to search for an item by ID
void Menu::searchItemByID()
{
    int id;

    while (true)
    {
        std::cout << "Enter item ID to search: ";
        std::cin >> id;
        if (std::cin.fail() || id <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ID must be a positive number. Try again.\n";
        }
        else {
            break;
        }
    }

    auto item = inventory.searchItemByID(id);
    printItem(item);
}

// Method to filter items by quantity range
void Menu::filterItemsByQuantity() {
    int minQuantity, maxQuantity;

    while (true) {
        std::cout << "Enter minimum quantity: ";
        std::cin >> minQuantity;
        if (std::cin.fail() || minQuantity < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Minimum quantity must be a non-negative number. Try again.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        std::cout << "Enter maximum quantity: ";
        std::cin >> maxQuantity;
        if (std::cin.fail() || maxQuantity < minQuantity) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Maximum quantity must be greater than or equal to minimum quantity. Try again.\n";
        }
        else {
            break;
        }
    }

    auto results = inventory.filterItemByQuantity(minQuantity, maxQuantity);
    for (const auto& item : results) {
        printItem(item);
    }
}

// Method to generate a report of all items in the inventory
void Menu::generateReport()
{
    auto report = inventory.generateReport();
    for (const auto& item : report)
    {
        printItem(item);
    }
}

// Method to print the details of an item
void Menu::printItem(const Item& item)
{
    std::cout << "ID: " << item.id << ", Name: " << item.name
        << ", Quantity: " << item.quantity << ", Price: " << item.price
        << ", Supplier: " << item.supplier << std::endl;
}
