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

TEST_CASE("Test create an empty list")
{
  Sorted_List l{};
  REQUIRE(l.is_empty() == true);
}

TEST_CASE("Test size")
{
  Sorted_List l{};
  l.insert(60);
  l.insert(70);
  REQUIRE(l.size() == 2);
}

TEST_CASE("Test print")
{
  Sorted_List l1{};
  l1.insert(10);
  l1.insert(30);
  l1.insert(2);
  REQUIRE(l1.print_test() == "2, 10, 30");
}

TEST_CASE("Test make list as string")
{
  Sorted_List l{};
  l.insert(1);
  l.insert(3);
  l.insert(0);
  REQUIRE(l.list_string() == "013");
}

TEST_CASE("Test get and then remove at certain index")
{
  Sorted_List l{};
  l.insert(40);
  l.insert(10);
  l.insert(30);
  l.insert(20);
  REQUIRE(l.list_string() == "10203040");
  REQUIRE(l.getValueAt(1) == 20);
  l.remove(1);
  REQUIRE(l.list_string() == "103040");
}

TEST_CASE("Test copy constructor")
{
  Sorted_List l1{};
  l1.insert(60);
  l1.insert(70);
  Sorted_List l2{l1};
  REQUIRE(l1.list_string() == l2.list_string());
  l1.clear_list();
  REQUIRE_FALSE(l1.list_string() == l2.list_string());
}

TEST_CASE("Test move constructor / move operator?")
{
  Sorted_List l1{};
  l1.insert(300);
  l1.insert(40);
  l1.insert(250);
  Sorted_List l2{};
  l2 = move(l1);

  REQUIRE(l2.list_string() == "40250300");
  REQUIRE(l1.is_empty());
  REQUIRE_FALSE(l1.list_string() == l2.list_string());
}

TEST_CASE("Test copy assignment operator")
{
  Sorted_List l1{};
  l1.insert(5000);
  l1.insert(2393);
  Sorted_List l2;
  l2 = l1;
  REQUIRE(l1.list_string() == l2.list_string());
  l1.clear_list();
  REQUIRE_FALSE(l1.list_string() == l2.list_string());
}

// It is your job to create new test cases and fully test your Sorted_List class
