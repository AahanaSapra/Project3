#include "Clothing.h"
#include "Book.h"
#include "Electronics.h"
#include <iostream>
#include <cassert> // for testing purposes
using namespace std;

int main() {
	// Initialize products
    Product* p1 = new Clothing("Hoodie", 29.99, "M");
    Product* p2 = new Book("The AI Era", 12.50, "J. Doe");
    Product* p3 = new Electronics("Bluetooth Speaker", 59.99, 24);
    Product* p4 = new Book("Harry Porter and the Cave of Death", 21.99, "Jonathan");
    Product* p5 = new Electronics("USB Cable", 20.00, 1);

	// Test Case 1: Verify printInfo() functionality for each product
    p1->printInfo();
    p2->printInfo();
    p3->printInfo();

    cerr << "START" << endl;

	// Test Case 2: Verify case insensitive keyword matching
    assert(p2->matchesKeyword("ai") == true);

	// Test Case 3: Verify proper handling of extra spaces in keyword
    assert(p3->matchesKeyword("Speaker") == true);
    assert(p3->matchesKeyword("  Speaker") == false);

    // Test Case 4: Verify proper substring identification
    assert(p4->matchesKeyword("than") == true);
    assert(p3->matchesKeyword("month") == true);

    // Test Case 5: Verify proper substring identification when separated by space
    assert(p3->matchesKeyword("4 month") == true);

	// Test Case 6: Verify proper handling of attempt to search multiple fields simultaneously
    assert(p1->matchesKeyword("Hoodie M") == false);

	// Test Case 7: Verify proper handling of empty keyword or only whitespace
    assert(p1->matchesKeyword("") == false);
    assert(p1->matchesKeyword("   ") == false);

    // Test Case 8: Verify singular warranty (1 month) still uses plural "months"
    p5->printInfo();
    assert(p5->matchesKeyword("1 months") == true);
    assert(p5->matchesKeyword("1 month") == true);

    // Test Case 9: Verify proper trailing whitespace and other whitespace (tab/newline only) handling
    assert(p1->matchesKeyword("Hoodie  ") == false);
    assert(p1->matchesKeyword("\t\n") == false);

	// Test Case 10: Verify clothing size field matching (case insensitivity and multiple char str)
    assert(p1->matchesKeyword("m") == true);
    assert(p1->matchesKeyword("XL") == false);

	// Test Case 11: Verify polymorphic behavior of getCategory() and getName()/getPrice() methods
    assert(p1->getCategory() == "Clothing");
    assert(p2->getCategory() == "Book");
    assert(p3->getCategory() == "Electronics");
    assert(p5->getPrice() == 20.00);

    cerr << "SUCCESS!" << endl;

	// Delete dynamically allocated memory
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}