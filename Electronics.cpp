#include "Electronics.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Implement constructor, destructor, getCategory, matchesKeyword, printInfo

// Implement constructor
Electronics::Electronics(const string& name, double price, int warrantyMonths)
	: Product(name, price), m_warrantyMonths(warrantyMonths) {
}

// Implement destructor
Electronics::~Electronics() {}

// Implement getCategory()
string Electronics::getCategory() const {
	return "Electronics";
}

// Implement matchesKeyword()
bool Electronics::matchesKeyword(const string& keyword) const {
	// Empty keyword or only whitespace -> return false
	if (keyword.empty() || keyword.find_first_not_of(" \t\n\r\f\v") == string::npos) {
		return false;
	}

	// Search name field
	if (stringLower(getName()).find(stringLower(keyword)) != string::npos) {
		return true;
	}

	// Search warranty field (number followed by " months" even if singular month)
	string warrantyStr = to_string(m_warrantyMonths) + " months";
	if (stringLower(warrantyStr).find(stringLower(keyword)) != string::npos) {
		return true;
	}

	return false;
}

// Implement printInfo()
void Electronics::printInfo() const {
	cout << "Category: " << getCategory() << " | "
		 << "Name: " << getName() << " | "
		 << "Price: " << fixed << setprecision(2) << getPrice()
		 << "Warranty: " << m_warrantyMonths << " months" << endl;
}