#include "Clothing.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Implement constructor, destructor, getCategory, matchesKeyword, printInfo

// Implement constructor
Clothing::Clothing(const std::string& name, double price, const std::string& size)
	: Product(name, price), m_size(size) {
}

// Implement destructor
Clothing::~Clothing() {}

// Implement getCategory()
std::string Clothing::getCategory() const {
	return "Clothing";
}

// Implement matchesKeyword()
bool Clothing::matchesKeyword(const std::string& keyword) const {}

// Implement printInfo()
void Clothing::printInfo() const {}