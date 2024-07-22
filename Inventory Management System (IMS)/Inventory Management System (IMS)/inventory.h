#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <map>

// Structure representing an item in the inventory
struct Item
{
	std::string name;
	int id;
	int quantity;
	double price;
	std::string supplier;

	// Constructor to initialize an item
	Item(std::string name,int id ,int quantity, double price, std::string supplier)
		:name(name), id(id), quantity(quantity), price(price), supplier(supplier){}

	Item() : name(""), id(0), quantity(0), price(0.0), supplier("") {}

};

//Class representing the inventory system
class Inventory
{
private:
	std::map<int, Item> items; //Map of items with their ID as the key
	int generateUniqueID(); // Generate a unique Id for each item

public:
	// Methods to manipulate the inventory
	void addItem(const std::string& name, int quantity, double price, const std::string& supplier);
	void updateItem(int id, int quantity, double price, const std::string& supplier);
	void deleteItem(int id);
	std::vector<Item> searchItemByName(const std::string& name);
	Item searchItemByID(int id);
	std::vector<Item> filterItemByQuantity(int minQuantity, int maxQuantity);
	std::vector<Item> generateReport();

};


#endif // INVENTORY_H

