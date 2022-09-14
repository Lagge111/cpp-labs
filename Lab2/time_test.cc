#include "catch.hpp"
#include "time.h"
#include <string>

TEST_CASE ("Test is_valid()") 
{
    Time t1 {23, 10, 50};
    REQUIRE(is_valid(t1));

    Time t2 {26, 20, 9};
    REQUIRE_FALSE(is_valid(t2));

    Time t3 {00, 00, 80};
    REQUIRE_FALSE(is_valid(t3));

    Time t4 {00, 80, 00};
    REQUIRE_FALSE(is_valid(t4));
}

TEST_CASE ("Test is_am()")
{
    Time t1 {10, 14, 16};
    REQUIRE(is_am(t1));

    Time t2 {16, 20, 40};
    REQUIRE_FALSE(is_am(t2));

    Time t3 {25, 40, 80};
    REQUIRE_FALSE(is_am(t3));

    Time t4 {12, 00, 00};
    REQUIRE_FALSE(is_am(t4));

    Time t5 {00, 00, 00};
    REQUIRE(is_am(t5));

}

TEST_CASE ("Test to_string()") 
{
    Time t1 {14, 24, 44};
    std::string format_24{"14:24:44"};
    REQUIRE(to_string(t1, 0) == format_24);

    std::string format_12{"02:24:44"};
    REQUIRE(to_string(t1, 1) == format_12);

    Time t2 {12, 00, 00};    
    std::string format_24_2{"12:00:00"};
    REQUIRE(to_string(t2, 0) == format_24_2);

    Time t3 {22, 30, 30};
    std::string format_24_3{"22:30:30"};
    REQUIRE(to_string(t3, 0) == format_24_3);

    Time t4 {23, 54, 34};
    std::string format_24_4{"23:54:34"};
    REQUIRE_FALSE(to_string(t4, 2) == format_24_4);
}

TEST_CASE ("Test \"+\" operator")
{
    Time t1 {23, 59, 59};
    Time t2 {00, 00, 01};
    t2 = t1 + 3603;
    CHECK(to_string(t2, 0) == "01:00:02");

    Time t3 {12, 30, 50};
    t3 = t3 + 5;
    CHECK(to_string(t3, 0) == "12:30:55");
}

TEST_CASE ("Test \"-\" operator")
{
    Time t1 {00, 00, 59};
    CHECK( to_string(t1 - 120, 0) == "23:58:59");

    Time t2 {00, 00, 00};
    CHECK( to_string(t2 - 3603, 0) == "22:59:57");
 
    Time t3 {23, 59, 59};
    CHECK( to_string(t3 - 63, 0) == "23:58:56");

    Time t4 {12, 40, 50};
    Time t5 {12, 40, 50};
    CHECK( to_string(t4 - (3600*24), 0) == to_string(t5, 0));
}

TEST_CASE ("Test \"++\" operator")
{
    Time t1 {22, 30, 50};
    t1 = ++t1;
    CHECK(to_string(t1, 0) == "22:30:51");

    Time t2 {22, 30, 50};
    t2 = t2++;
    CHECK(to_string(t2, 0) == "22:30:51");

    Time t3 {23, 59, 59};
    t3 = t3++;
    CHECK(to_string(t3, 0) == "00:00:00");
}

TEST_CASE ("Test \"--\" operator")
{
    Time t1 {22, 30, 50};
    t1 = --t1;
    CHECK(to_string(t1, 0) == "22:30:49");

    Time t2 {22, 30, 50};
    t2 = t2--;
    CHECK(to_string(t2, 0) == "22:30:49");
}

TEST_CASE ("Test \"<\" operator")
{
    Time t1 {12, 40, 02};
    Time t2 {13, 30, 03};
    CHECK(t1 < t2);

    Time t3 {12, 03, 04};
    Time t4 {12, 03, 03};
    REQUIRE_FALSE(t3 < t4);

    Time t5 {12, 03, 03};
    Time t6 {12, 03, 03};
    REQUIRE_FALSE(t5 < t6);
}

TEST_CASE ("Test \">\" operator")
{
    Time t1 {13, 40, 03};
    Time t2 {12, 30, 02};
    CHECK(t1 > t2);

    Time t3 {12, 03, 02};
    Time t4 {12, 03, 03};
    REQUIRE_FALSE(t3 > t4);

    Time t5 {12, 03, 03};
    Time t6 {12, 03, 03};
    REQUIRE_FALSE(t5 > t6);
}

TEST_CASE ("Test \"==\" operator")
{
    Time t1 {12, 03, 03};
    Time t2 {12, 03, 03};
    CHECK(t1 == t2);

    Time t3 {12, 03, 03};
    Time t4 {12, 03, 04};
    REQUIRE_FALSE(t3 == t4);

    Time t5 {12, 03, 04};
    Time t6 {12, 03, 03};
    REQUIRE_FALSE(t5 == t6);
}

TEST_CASE ("Test \">=\" operator")
{
    Time t1 {13, 30, 03};
    Time t2 {12, 40, 06};
    CHECK(t1 >= t2);

    Time t3 {12, 03, 04};
    Time t4 {12, 03, 03};
    CHECK(t3 >= t4);

    Time t5 {12, 03, 03};
    Time t6 {12, 03, 04};
    REQUIRE_FALSE(t5 >= t6);
}

TEST_CASE ("Test \"<=\" operator")
{
    Time t1 {12, 30, 03};
    Time t2 {13, 40, 03};
    CHECK(t1 <= t2);

    Time t3 {12, 03, 03};
    Time t4 {12, 03, 04};
    CHECK(t3 <= t4);

    Time t5 {12, 03, 04};
    Time t6 {12, 03, 03};
    REQUIRE_FALSE(t5 <= t6);
}

TEST_CASE ("Test \"<<\" operator")
{
    Time t1 {12, 30, 45};
    std::ostringstream test{};
    test << t1;
    CHECK(test.str() == to_string(t1, 0));
}

TEST_CASE ("Test \">>\" operator")
{
    Time t1{};
    std::istringstream iss{"12:30:50"};
    iss >> t1;
    CHECK(iss.good());
    CHECK(to_string(t1, 0) == "12:30:50");

    Time t2{};
    std::istringstream iss2{"12:30:55"};
    iss2 >> t2;
    CHECK(iss2.good());
    REQUIRE_FALSE(to_string(t2, 0) == "11:41:50");
    
    Time t3{};
    std::istringstream iss3{"12:80:55"};
    iss3 >> t3;
    CHECK(iss3.fail());
    REQUIRE_FALSE(to_string(t3, 0) == "11:41:50");
    REQUIRE_FALSE(to_string(t3, 0) == "12:80:55");
}