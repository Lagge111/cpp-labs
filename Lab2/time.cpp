#include "time.h"
#include <sstream>
#include <iomanip>
using namespace std;

// TODO: Complementary work needed: The post/prefix operators are not correctly implemented.
/*
 * Fixed by correctly implementing postfix/prefix operators.
 */

// TODO: Complementary work needed: Don't take an argument as const & if the
// first thing you do is make a copy.
/*
 * Fixed by using 'const &' only where necessary, according to the complementary
 * work comment.
 */

// TODO: Complementary work needed: if your functions only return true or
// false with one condition then you should change it to return condition or
// !(condition). For ex: if (t1 < t2) {return false} --> return !(t1 < t2)
/*
 * Fixed by removing unnecessary if-statements and changing the return statements.
 */

// TODO: Complementary work needed: operator>> normally
// only read until an error occur and the stop. If you choose
// to implement this in a different way, it is OK as long as you
// document it (by writing a comment in the header file).
/*
 * Fixed by also checking the format of the input, and by adding 
 * documentation regarding our implementation in the header file. 
 */

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

    if (twelve_format) {
        oss << append;
    };

    return oss.str();
}

/*
 * Removed helper function for addition since 
 * we only use this code here now 
 */
Time operator+(Time &time, int n)
{
    time.sec += n;
    time.min += (time.sec / 60);
    time.sec = time.sec % 60;
    time.hour += (time.min / 60);
    time.min = time.min % 60;
    time.hour = time.hour % 24;
    return time;
}

/*
 * Removed helper function for subtraction since
 * we only use this code here now 
 */
Time operator-(Time &time, int n)
{
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
    if (time.hour < 0)
    {
        time.hour += 24;
    }
    return time;
}

Time &operator++(Time &time)
{
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

Time operator++(Time &time, int n)
{
    Time temp_time{time};
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
    return temp_time;
}

Time &operator--(Time &time)
{
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

Time operator--(Time &time, int n)
{
    Time temp_time{time};
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

bool operator==(Time const &time1, Time const &time2)
{
    return !(time1 < time2 || time1 > time2);
}

bool operator!=(Time const &time1, Time const &time2)
{
    return !(time1 == time2);
}

bool operator>=(Time const &time1, Time const &time2)
{
    return (time1 > time2 || time1 == time2);
}

bool operator<=(Time const &time1, Time const &time2)
{
    return (time1 < time2 || time1 == time2);
}

ostream &operator<<(ostream &os, Time const &time)
{
    os << to_string(time, 0);
    return os;
}

istream &operator>>(istream &is, Time &time)
{
    char c1{};
    char c2{};
    Time temp{};
    is >> temp.hour >> c1 >> temp.min >> c2 >> temp.sec;

    if(!is_valid(temp) || c1 != ':' || c2 != ':') {
        is.setstate(ios_base::failbit);
    } else {
        time = temp;
    }

    return is;
}
