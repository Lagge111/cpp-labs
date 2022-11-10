#include "catch.hpp"
#include "sorted_list.h"
using namespace std;

// TODO: Complementary work needed: Test cases insufficient, when testing move and
// copy assignment you should also test when both lists have content.
/**
 * Fixed by adding additional tests for copy and move assignment operators.
 */

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Test creating an empty list")
{
  Sorted_List l{};
  REQUIRE(l.is_empty() == true);
}

TEST_CASE("Test insert and size")
{
  Sorted_List l{};
  l.insert(60);
  l.insert(70);
  l.insert(4);
  l.insert(24);
  l.insert(-5);
  REQUIRE(l.size() == 5);
}

TEST_CASE("Test print")
{
  Sorted_List l1{};
  l1.insert(10);
  l1.insert(-23);
  l1.insert(30);
  l1.insert(0);
  l1.insert(2);
  REQUIRE(l1.print() == "-23 -> 0 -> 2 -> 10 -> 30");
}

TEST_CASE("Test getValueAt and then remove at certain index")
{
  Sorted_List l{};
  l.insert(40);
  l.insert(10);
  l.insert(30);
  l.insert(20);
  REQUIRE(l.getValueAt(1) == 20);
  l.remove(1);
  REQUIRE(l.size() == 3);
  REQUIRE(l.print() == "10 -> 30 -> 40");
}

TEST_CASE("Test copy constructor")
{
  Sorted_List l1{};
  l1.insert(60);
  l1.insert(70);
  Sorted_List l2{l1};
  REQUIRE(l1.print() == l2.print());
  l1.clear_list();
  REQUIRE(l1.size() == 0);
  REQUIRE_FALSE(l1.print() == l2.print());
}

TEST_CASE("Test move assignment operator")
{
  Sorted_List l1{};
  l1.insert(300);
  l1.insert(40);
  l1.insert(250);
  Sorted_List l2{};
  l2 = move(l1);
  REQUIRE(l2.print() == "40 -> 250 -> 300");
  REQUIRE(l1.is_empty());
  REQUIRE_FALSE(l1.print() == l2.print());

  l1.insert(10);
  l1.insert(9);
  l1.insert(35);
  REQUIRE(l1.print() == "9 -> 10 -> 35");
  // Both lists have content. l1 == "9 -> 10 -> 35" and l2 == "40 -> 250 -> 300"
  l2 = move(l1);
  REQUIRE(l2.print() == "9 -> 10 -> 35");
  REQUIRE(l1.is_empty());
}

TEST_CASE("Test move constructor")
{
  Sorted_List l1{};
  l1.insert(300);
  l1.insert(40);
  l1.insert(250);
  Sorted_List l2{move(l1)};
  REQUIRE(l2.print() == "40 -> 250 -> 300");
  REQUIRE(l1.is_empty());
  REQUIRE_FALSE(l1.print() == l2.print());
}

TEST_CASE("Test copy assignment operator")
{
  Sorted_List l1{};
  l1.insert(5000);
  l1.insert(2393);
  Sorted_List l2;
  l2 = l1;
  REQUIRE(l1.print() == l2.print());
  l1.clear_list();
  REQUIRE(l1.size() == 0);
  REQUIRE_FALSE(l1.print() == l2.print());

  l1.insert(10);
  l1.insert(9);
  l1.insert(35);
  // Both lists have content. l1 == "9 -> 10 -> 35" and l2 == "2393 -> 5000"
  l2 = l1;
  REQUIRE(l2.print() == "9 -> 10 -> 35");
  REQUIRE(l1.print() == l2.print());
}
