#include "Product.h"
#include <iostream>
#include <cctype>

Product::Product(std::string name, double price)
    : m_name(name), m_price(price) {}
Product::~Product() {}

std::string Product::getName() const { return m_name; }
double Product::getPrice() const { return m_price; }

// Implement helper function to convert string to lowercase for case-insensitive comparisons
// passing signed char = undefined behavior if string contains non-ASCII char
std::string Product::stringLower(const std::string& str) const {
    std::string res = str;

    for (char& c : res) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    return res;
}

// Implement helper function to check if a keyword is empty or only whitespace
bool Product::checkEmptyOrWhitespace(const std::string& keyword) const {
	return (keyword.empty() || keyword.find_first_not_of(" \t\n\r\f\v") == std::string::npos);
}

// Implement helper function to check if the keyword is a substring of the product's name
bool Product::checkName(const std::string& keyword) const {
    return (stringLower(getName()).find(stringLower(keyword)) != std::string::npos);
}