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

// Implement matchesKeyword() to search for a keyword in the name or size fields
bool Clothing::matchesKeyword(const string& keyword) const {
	// Empty keyword or only whitespace -> return false
	if (!checkEmptyOrWhitespace(keyword)) {
		// Search name field
		if (checkName(keyword)) {
			return true;
		}

		// Search size field
		if (stringLower(m_size).find(stringLower(keyword)) != string::npos) {
			return true;
		}
	}

	return false;
}

// Implement printInfo()
void Clothing::printInfo() const {
	cout << "Category: " << getCategory() << " | "
		 << "Name: " << getName() << " | "
		 << "Price: " << fixed << setprecision(2) << getPrice() << " | "
		 << "Size: " << m_size << endl;
}