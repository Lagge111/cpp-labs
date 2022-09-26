#include "time.h"
#include <sstream>
#include <iomanip>
using namespace std;

// TODO: Complementary work needed: The post/prefix operators are not correctly implemented.
/*
Fixed by correctly implementing post-/prefix operators,
by returning temp variables for the postfix versions.
*/

// TODO: Complementary work needed: Don't take an argument as const & if the
// first thing you do is make a copy.

// TODO: Complementary work needed: if your functions only return true or
// false with one condition then you should change it to return condition or
// !(condition). For ex: if (t1 < t2) {return false} --> return !(t1 < t2)
/*
Fixed by removing unnecessary if-statements and changing the return statements.
*/

// TODO: Complementary work needed: operator>> normally
// only read until an error occur and the stop. If you choose
// to implement this in a different way, it is OK as long as you
// document it (by writing a comment in the header file).

bool is_valid(Time const &time)
{
    return ((time.hour < 24 && time.hour >= 0) &&
            (time.min < 60 && time.min >= 0) &&
            (time.sec < 60 && time.sec >= 0));
};

bool is_am(Time const &time)
{
    return (time.hour < 12);
};

string to_string(Time const &time, bool twelve_format)
{
    string append{};
    bool pm{false};
    ostringstream oss{};

    if (twelve_format)
    {
        if (is_am(time))
        {
            append = " am";
        }
        else
        {
            append = " pm";
            pm = true;
        }
    }
    oss << setfill('0')
        << setw(2) << time.hour - (12 * pm) << ":"
        << setw(2) << time.min << ":"
        << setw(2) << time.sec;

    return oss.str();
}

/* Removed helper function for addition since we only use it here now */
Time operator+(Time const &time, int n)
{
    // return timeAdd(time, n);
    Time temp_time{time};
    temp_time.sec += n;
    temp_time.min += (temp_time.sec / 60);
    temp_time.sec = temp_time.sec % 60;
    temp_time.hour += (temp_time.min / 60);
    temp_time.min = temp_time.min % 60;
    temp_time.hour = temp_time.hour % 24;
    return temp_time;
}

/* Removed helper function for subtraction since we only use it here now */
Time operator-(Time const &time, int n)
{
    // return timeSub(time, n);

    Time temp_time{time};
    temp_time.sec -= (n % 60);
    temp_time.min -= ((temp_time.sec + n) / 60) % 60;
    temp_time.hour -= ((temp_time.sec + n) / 60) / 60;

    if (temp_time.sec < 0)
    {
        temp_time.min--;
        temp_time.sec += 60;
    }
    if (temp_time.min < 0)
    {
        temp_time.hour--;
        temp_time.min += 60;
    }
    while (temp_time.hour < 0)
    {
        temp_time.hour += 24;
    }
    return temp_time;
}

/*
Fixed prefix addition by not calling a helper function.
*/
Time operator++(Time &time)
{
    // return timeAdd(time, 1);

    time.sec++;
    if (time.sec >= 60)
    {
        time.sec -= 60;
        time.min++;
    }
    if (time.min >= 60)
    {
        time.min -= 60;
        time.hour++;
    }
    if (time.hour >= 24)
    {
        time.hour -= 24;
    }
    return time;
}

/*
Fixed postfix addition by not calling a helper function,
and by returning a temp variable.
*/
Time operator++(Time const &time, int n)
{
    // Time temp_time{time};
    // return timeAdd(temp_time, 1);

    Time temp_time{time};
    temp_time.sec++;
    if (temp_time.sec >= 60)
    {
        temp_time.sec -= 60;
        temp_time.min++;
    }
    if (temp_time.min >= 60)
    {
        temp_time.min -= 60;
        temp_time.hour++;
    }
    if (temp_time.hour >= 24)
    {
        temp_time.hour -= 24;
    }
    return temp_time;
}

/*
Fixed prefix subtraction by not calling a helper function.
*/
Time operator--(Time &time)
{
    // return timeSub(time, 1);

    time.sec--;
    if (time.sec < 0)
    {
        time.sec += 60;
        time.min--;
    }
    if (time.min < 0)
    {
        time.min += 60;
        time.hour--;
    }
    if (time.hour < 0)
    {
        time.hour += 24;
    }
    return time;
}

/*
Fixed postfix subtraction by not calling a helper function,
and by returning a temp variable.
*/
Time operator--(Time const &time, int n)
{
    // Time temp_time{time};
    // return timeSub(temp_time, 1);

    Time temp_time{time};
    temp_time.sec--;
    if (temp_time.sec < 0)
    {
        temp_time.sec += 60;
        temp_time.min--;
    }
    if (temp_time.min < 0)
    {
        temp_time.min += 60;
        temp_time.hour--;
    }
    if (temp_time.hour < 0)
    {
        temp_time.hour += 24;
    }
    return temp_time;
}

bool operator<(Time const &time1, Time const &time2)
{
    if (time1.hour < time2.hour)
    {
        return true;
    }
    else if (time1.hour == time2.hour)
    {
        if (time1.min < time2.min)
        {
            return true;
        }
        else if (time1.min == time2.min)
        {
            if (time1.sec < time2.sec)
            {
                return true;
            }
            else if (time1.sec == time2.sec)
            {
                return false;
            }
        }
    }
    return false;
}

bool operator>(Time const &time1, Time const &time2)
{
    if (time1.hour > time2.hour)
    {
        return true;
    }
    else if (time1.hour == time2.hour)
    {
        if (time1.min > time2.min)
        {
            return true;
        }
        else if (time1.min == time2.min)
        {
            if (time1.sec > time2.sec)
            {
                return true;
            }
            else if (time1.sec == time2.sec)
            {
                return false;
            }
        }
    }
    return false;
}

/* Removed if-statement */
bool operator==(Time const &time1, Time const &time2)
{
    // if (time1 < time2 || time1 > time2)
    // {
    //     return false;
    // }
    // return true;
    return !(time1 < time2 || time1 > time2);
}

/* Removed if-statement */
bool operator!=(Time const &time1, Time const &time2)
{
    // if (time1 == time2)
    // {
    //     return false;
    // }
    // return true;
    return !(time1 == time2);
}

/* Removed if-statement */
bool operator>=(Time const &time1, Time const &time2)
{
    // if (time1 > time2 || time1 == time2)
    // {
    //     return true;
    // }
    // return false;
    return (time1 > time2 || time1 == time2);
}

/* Removed if-statement */
bool operator<=(Time const &time1, Time const &time2)
{
    // if (time1 < time2 || time1 == time2)
    // {
    //     return true;
    // }
    // return false;
    return (time1 < time2 || time1 == time2);
}

ostream &operator<<(ostream &os, Time const &time)
{
    os << to_string(time, 0);
    return os;
}

istream &operator>>(istream &is, Time &time)
{
    char c{};
    Time temp{};
    is >> temp.hour >> c >> temp.min >> c >> temp.sec;
    is.clear();
    if (is_valid(temp))
    {
        time = temp;
        is.setstate(ios_base::goodbit);
    }
    else
    {
        is.setstate(ios_base::failbit);
    }
    return is;
}

/*
Removed helper functions since we only use this code in one place.
*/

/*  Helper functions for adding and subtracting time,
    used in the functions for the operators
    "+", "-", "++" and "--".
*/

/*Time timeAdd(Time time, int n)
{
    // Time time_tmp{time};
    time.sec += n;
    time.min += (time.sec / 60);
    time.sec = time.sec % 60;
    time.hour += (time.min / 60);
    time.min = time.min % 60;
    time.hour = time.hour % 24;
    return time;
}*/

/*Time timeSub(Time time, int n)
{
    // Time time_tmp{time};
    time.sec -= (n % 60);
    time.min -= ((time.sec + n) / 60) % 60;
    time.hour -= ((time.sec + n) / 60) / 60;

    if (time.sec < 0)
    {
        time.min--;
        time.sec += 60;
    }
    if (time.min < 0)
    {
        time.hour--;
        time.min += 60;
    }
    while (time.hour < 0)
    {
        time.hour += 24;
    }
    return time;
}*/
