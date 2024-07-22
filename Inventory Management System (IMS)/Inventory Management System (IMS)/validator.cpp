#include "validator.h"

// Validate the length of a string
bool Validator::validateString(const std::string& str, size_t minLength, size_t maxLength)
{
	return str.length() >= minLength && str.length() <= maxLength;
}

// Validate that the quantity is positive
bool Validator::validateQuantity(int quantity)
{
	return quantity > 0;
}

// Validate that the price is positive
bool Validator::validatePrice(double price)
{
	return price > 0.0;
}