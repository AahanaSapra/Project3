#include "Electronics.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Implement constructor, destructor, getCategory, matchesKeyword, printInfo

// Implement constructor
Electronics::Electronics(const std::string& name, double price, int warrantyMonths)
	: Product(name, price), m_warrantyMonths(warrantyMonths) {
}

// Implement destructor
Electronics::~Electronics() {}

// Implement getCategory()
std::string Electronics::getCategory() const {
	return "Electronics";
}

// Implement matchesKeyword()
bool Electronics::matchesKeyword(const std::string& keyword) const {}

// Implement printInfo()
void Electronics::printInfo() const {}