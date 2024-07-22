#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

// Class for validating user input
class Validator
{
public:
    static bool validateString(const std::string& str, size_t minLength, size_t maxLength);
    static bool validateQuantity(int quantity);
    static bool validatePrice(double price);
};

#endif // VALIDATOR_H