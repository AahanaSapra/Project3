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

	// Test Case 1: Verify printInfo() functionality for each product
    p1->printInfo();
    p2->printInfo();
    p3->printInfo();

    cerr << "Start of assertion tests" << endl;

	// Test Case 2: Verify case insensitive keyword matching
    assert(p2->matchesKeyword("ai") == true);

	// Test Case 3: Verify proper handling of leading spaces in keyword
    assert(p3->matchesKeyword("Speaker") == true);
    assert(p3->matchesKeyword("  Speaker") == false);

    // Test Case 4: Verify proper substring identification
    Product* p4 = new Book("Harry Porter and the Cave of Death", 21.99, "Jonathan");
    assert(p4->matchesKeyword("than") == true);
    assert(p3->matchesKeyword("month") == true);

    // Test Case 5: Verify proper substring identification when separated by space
    assert(p3->matchesKeyword("4 month") == true);

	// Test Case 6: Verify proper handling of attempt to search multiple fields simultaneously
    assert(p1->matchesKeyword("Hoodie M") == false);

	// Test Case 7: Verify proper handling of empty keyword or only whitespace
    assert(p1->matchesKeyword("") == false);
    assert(p1->matchesKeyword("   ") == false);

    cerr << "SUCCESS!" << endl;

	// Delete dynamically allocated memory
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}