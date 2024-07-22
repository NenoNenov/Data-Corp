#include "inventory.h"
#include <iostream>
#include <algorithm>

// Generate a unique ID for each item
int Inventory::generateUniqueID() {
    static int id = 0; 
    return ++id;
}

// Add a new item to the inventory
void Inventory::addItem(const std::string& name, int quantity, double price, const std::string& supplier)
{
    int id = generateUniqueID();  // Generate a unique ID for the new item
    items[id] = Item(name, id, quantity, price, supplier);
}

// Update an existing item in the inventory
void Inventory::updateItem(int id, int quantity, double price, const std::string& supplier)
{
    
    if (items.find(id) != items.end())
    {
        items[id].quantity = quantity;
        items[id].price = price;
        items[id].supplier = supplier;
    }
    else {
        std::cerr << "Item with ID" << id << "not found \n"; // Съобщение за грешка, ако артикулът не е намерен
    }
 
}
// Delete an item from the inventory
void Inventory::deleteItem(int id)
{
    items.erase(id);
}

// Search for items by name
std::vector<Item> Inventory::searchItemByName(const std::string& name)
{
    std::vector<Item> results;
    for (const auto& pair : items)
    {
        if (pair.second.name == name) {
            results.push_back(pair.second);
        }
    }
    return results;
}

// Search for an item by ID
Item Inventory::searchItemByID(int id)
{
    if (items.find(id) != items.end())
    {
        return items[id];
    }
    else
    {
        std::cerr << "Item with ID" << id << "not found. \n";
        return Item("", 0, 0, 0.0, "");
    }
}

// Filter items by quantity range
std::vector<Item> Inventory::filterItemByQuantity(int minQuantity, int maxQuantity)
{
    std::vector<Item> results;
    for (const auto& pair : items) {
        if (pair.second.quantity >= minQuantity && pair.second.quantity <= maxQuantity)
        {
            results.push_back(pair.second);
        }
    }
    return results;
}

// Generate a report of all items in the inventory
std::vector<Item> Inventory::generateReport()
{
    std::vector<Item> report;
    for (const auto& pair : items)
    {
        report.push_back(pair.second);
    }

    return report;
}