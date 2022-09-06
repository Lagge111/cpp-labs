#include "catch.hpp"
#include "time.h"

TEST_CASE ("Test is_valid()") 
{
    Time t1 {23, 10, 50};
    REQUIRE( is_valid(t1) );

    Time t2 {26, 20, 9};
    REQUIRE_FALSE( is_valid(t2) );

}

TEST_CASE ("Test is_am()")
{
    Time t1 {10, 14, 16};
    REQUIRE( is_am(t1) );

    Time t2 {16, 20, 40};
    REQUIRE_FALSE( is_am(t2) );

}

TEST_CASE ("Test to_string()") 
{
    Time t1 {14, 24, 44};
    std::string frmt_24{"14:24:44"};
    REQUIRE( to_string(t1, 0) == frmt_24 );

    std::string frmt_12{"02:24:44"};
    REQUIRE( to_string(t1, 1) == frmt_12 );

    Time t2 {12, 00, 00};    
    std::string frmt_24_test{"12:00:00"};
    REQUIRE( to_string(t2, 0) == frmt_24_test );

}

TEST_CASE ("Test \"+\" operator")
{
    Time t1 {23, 59, 59};
    Time t2 {00, 00, 01};
    t2 = t1 + 3603;
    CHECK(t2.sec == 2);
    CHECK(t2.min == 0);
    CHECK(t2.hour == 1);

    Time t3 {12, 30, 50};
    t3 = t3 + 5;
    CHECK(t3.sec == 55);
    CHECK(t3.min == 30);
    CHECK(t3.hour == 12);
    
}

TEST_CASE ("Test \"-\" operator")
{
    Time t1 {00, 00, 59};
    CHECK( to_string(t1 - 120, 0) == "23:58:59");

    Time t2 {00, 00, 00};
    CHECK( to_string(t2 - 3603, 0) == "22:59:57");
 
    Time t3 {23, 59, 59};
    CHECK( to_string(t3 - 63, 0) == "23:58:56");

}

TEST_CASE ("Test \"++\" operator")
{
    Time t1 {22, 30, 50};
    t1 = ++t1;
    CHECK(t1.sec == 51);
    CHECK(t1.min == 30);
    CHECK(t1.hour == 22);
    
    Time t2 {22, 30, 50};
    t2 = t2++;
    CHECK(t2.sec == 51);
    CHECK(t2.min == 30);
    CHECK(t2.hour == 22);
    
}

TEST_CASE ("Test \"--\" operator")
{
    Time t1 {22, 30, 50};
    t1 = --t1;
    CHECK(t1.sec == 49);
    CHECK(t1.min == 30);
    CHECK(t1.hour == 22);

    Time t2 {22, 30, 50};
    t2 = t2--;
    CHECK(t2.sec == 49);
    CHECK(t2.min == 30);
    CHECK(t2.hour == 22);
}

TEST_CASE ("Test \"<\" operator")
{
    Time t1 {12, 03, 02};
    Time t2 {12, 03, 03};
    CHECK(t1 < t2);
}

TEST_CASE ("Test \">\" operator")
{
    Time t1 {12, 03, 03};
    Time t2 {12, 03, 02};
    CHECK(t1 > t2);
}

TEST_CASE ("Test \"==\" operator")
{
    Time t1 {12, 03, 03};
    Time t2 {12, 03, 03};
    CHECK(t1 == t2);
}

TEST_CASE ("Test \">=\" operator")
{
    Time t1 {12, 03, 03};
    Time t2 {12, 03, 03};
    CHECK(t1 >= t2);
}

TEST_CASE ("Test \"<=\" operator")
{
    Time t1 {12, 03, 03};
    Time t2 {12, 03, 03};
    CHECK(t1 <= t2);
}
