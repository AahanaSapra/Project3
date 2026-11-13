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
bool Electronics::matchesKeyword(const string& keyword) const {}

// Implement printInfo()
void Electronics::printInfo() const {
	cout << "Category: " << getCategory() << " | "
		 << "Name: " << getName() << " | "
		 << "Price: " << fixed << setprecision(2) << getPrice()
		 << "Warranty: " << m_warrantyMonths << " months" << endl;
}