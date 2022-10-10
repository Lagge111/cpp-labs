// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "sorted_list.h"
#include <random>
#include <iostream>
using namespace std;

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};
  REQUIRE(l.is_empty() == true);
}

TEST_CASE( "Insert and remove values" ) {
  Sorted_List l{};
  l.insert(60);
  l.insert(70);
  l.insert(90);
  l.insert(50);
  l.insert(11);
  l.insert(8);
  l.insert(1);
  l.insert(9);
  REQUIRE(l.size() == 8);
  l.remove(3);
  REQUIRE(l.size() == 7);
  l.~Sorted_List();
  l.print();

}


// It is your job to create new test cases and fully test your Sorted_List class
