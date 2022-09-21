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
  l.insert(5);
  l.insert(3);
  l.insert(9);
  //REQUIRE(l.size() == 2);
  //l.insert(9);
  //l.insert(7);
  //l.insert(1);
  //l.insert(6);
  l.print();

  // REQUIRE(l.getValueAt(0) == 1);
  // REQUIRE(l.size() == 6);
  // REQUIRE(l.is_empty() == false);
  // l.print();
  // l.remove(2);
  // cout << l.size() << endl;
  // l.print();


  // REQUIRE( l.is_empty() == true );
  // REQUIRE( l.size() == 0 );
}

// It is your job to create new test cases and fully test your Sorted_List class
