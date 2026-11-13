#include "Product.h"
#include <iostream>

Product::Product(std::string name, double price)
    : m_name(name), m_price(price) {}
Product::~Product() {}

std::string Product::getName() const { return m_name; }
double Product::getPrice() const { return m_price; }

// Implement helper function to convert string to lowercase for case-insensitive comparisons
// TODO:: static_cast<char> and/or static_cast<unsigned char>
std::string Product::stringLower(const std::string& str) const {
    std::string res = str;

    for (char& c : res) {
        c = std::tolower(c);
    }

    return res;
}