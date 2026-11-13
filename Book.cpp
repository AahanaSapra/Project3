#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

// TODO: Implement constructor, destructor, getCategory, matchesKeyword, printInfo

// Implement constructor
// call base class constructor in initializer list
Book::Book(const std::string& name, double price, const std::string& author) 
	: Product(name, price), m_author(author) {}

// Implement destructor
// no dynamically allocated member variables to manually delete
Book::~Book() {}

// Implement getCategory()
std::string Book::getCategory() const {
	return "Book";
}

// Implement matchesKeyword()
bool Book::matchesKeyword(const std::string& keyword) const {}

// Implement printInfo()
void Book::printInfo() const {}