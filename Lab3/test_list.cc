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

TEST_CASE("Create an empty list")
{
  Sorted_List l{};
  REQUIRE(l.is_empty() == true);
}

TEST_CASE("Insert and remove values")
{
  Sorted_List l1{};
  l1.insert(60);
  l1.insert(70);
  REQUIRE(l1.size() == 2);
  l1.insert(90);
  l1.insert(50);
  l1.insert(11);
  l1.insert(8);
  l1.insert(1);
  l1.insert(9);
  REQUIRE(l1.size() == 8);
  l1.print();
  l1.remove(3);
  REQUIRE(l1.size() == 7);
  l1.print();

  Sorted_List l2{l1};
  l2.print();
  l2.remove(0);
  l2.print();
  l1.clear_list();
  REQUIRE(l1.is_empty() == true);

  Sorted_List list_move{};
  list_move = std::move(l2);
  REQUIRE(l2.is_empty() == true);
  REQUIRE(list_move.is_empty() == false);
  list_move.print();
  l2.print();
  l1.print();
}

TEST_CASE("Test copy constructor")
{
  Sorted_List l1{};

  l1.insert(60);
  l1.insert(70);

  Sorted_List l2{l1};
  l2.print();
  // getValueAt is wrong, works in reverse order.
  REQUIRE(l2.getValueAt(0) == 70);
}
// It is your job to create new test cases and fully test your Sorted_List class
