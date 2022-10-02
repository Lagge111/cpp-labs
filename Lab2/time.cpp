#include "time.h"
#include <sstream>
#include <iomanip>
using namespace std;

// TODO: Complementary work needed: The operator-
// doesn't work for:
// Time t{0,0,0}
// t-129600;
// expects to be "12:00:00" but gets "-12:00:00".
/**
 * Fixed by calculating hour % 24, and if it is
 * still a negative value, we are making it positive 
 * by adding 24. Could been done with less code through
 * a while-loop, but this solution gives us a
 * better time complexity.
 */

// TODO: Complementary work needed: operator+ and
// - should return a copy.
/**
 * Fixed by making operator + and - return copies.
 */

// TODO: Complementary work needed: operator ++ and --
// should reuse operator + and -
/**
 * Fixed by reusing operator + and - in operator ++ and --.
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

    if (twelve_format)
    {
        oss << append;
    };

    return oss.str();
}

Time operator+(Time const &time, int n)
{
    Time temp{time};
    temp.sec += n;
    temp.min += (temp.sec / 60);
    temp.sec = temp.sec % 60;
    temp.hour += (temp.min / 60);
    temp.min = temp.min % 60;
    temp.hour = temp.hour % 24;
    return temp;
}

Time operator-(Time const &time, int n)
{
    Time temp{time};
    temp.sec -= (n % 60);
    temp.min -= ((temp.sec + n) / 60) % 60;
    temp.hour -= ((temp.sec + n) / 60) / 60;

    int rest;

    if (temp.sec < 0)
    {
        temp.min--;
        temp.sec += 60;
    }
    if (temp.min < 0)
    {
        temp.hour--;
        temp.min += 60;
    }
    if (temp.hour < 0)
    {
        temp.hour = temp.hour % 24;
        if (temp.hour < 0) {
            temp.hour += 24;
        }
    }
    return temp;
}

Time &operator++(Time &time)
{
    time = time + 1;
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
    time = time + 1;
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
    time = time - 1;
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
    time = time - 1;
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

    if (!is_valid(temp) || c1 != ':' || c2 != ':')
    {
        is.setstate(ios_base::failbit);
    }
    else
    {
        time = temp;
    }

    return is;
}
