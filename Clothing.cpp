#include "Clothing.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Implement constructor, destructor, getCategory, matchesKeyword, printInfo

// Implement constructor
Clothing::Clothing(const string& name, double price, const string& size)
	: Product(name, price), m_size(size) {
}

// Implement destructor
Clothing::~Clothing() {}

// Implement getCategory()
string Clothing::getCategory() const {
	return "Clothing";
}

// Implement matchesKeyword()
bool Clothing::matchesKeyword(const string& keyword) const {
	// Empty keyword or only whitespace -> return false
	if (keyword.empty() || keyword.find_first_not_of(" \t\n\r\f\v") == string::npos) {
		return false;
	}

	// Search name field
	if (stringLower(getName()).find(stringLower(keyword)) != string::npos) {
		return true;
	}

	// Search size field
	if (stringLower(m_size).find(stringLower(keyword)) != string::npos) {
		return true;
	}

	return false;
}

// Implement printInfo()
void Clothing::printInfo() const {
	cout << "Category: " << getCategory() << " | "
		 << "Name: " << getName() << " | "
		 << "Price: " << fixed << setprecision(2) << getPrice()
		 << "Size: " << m_size << endl;
}