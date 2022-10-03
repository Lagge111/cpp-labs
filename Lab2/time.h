#ifndef TEST_H
#define TEST_H

#include <sstream>

struct Time
{
    int hour{};
    int min{};
    int sec{};
};

bool is_valid(Time const &time);

bool is_am(Time const &time);

std::string to_string(Time const &time, bool twelve_format);

Time operator+(Time const &time, int n);

Time operator-(Time const &time, int n);

Time &operator++(Time &time);

Time operator++(Time &time, int n);

Time &operator--(Time &time);

Time operator--(Time &time, int n);

bool operator<(Time const &time1, Time const &time2);

bool operator>(Time const &time1, Time const &time2);

bool operator==(Time const &time1, Time const &time2);

bool operator!=(Time const &time1, Time const &time2);

bool operator>=(Time const &time1, Time const &time2);

bool operator<=(Time const &time1, Time const &time2);

std::ostream &operator<<(std::ostream &os, Time const &time);

/**
 * Instead of checking the validity of each read value,
 * we check the validity of the entire time.
 * We read the values to a 'temp' variable to not change
 * the 'time' variable if the read values are incorrect.
 * By passing the 'temp' variable as a parameter to the
 * is_valid() function, we check if the actual time is
 * valid before assigning the value of the 'temp' variable
 * to the 'time' variable. We also check the format of the
 * input, so that we only "accept" colons between hour,
 * min and seconds before assigning the 'temp' variable
 * to the 'time' variable.
 * If the is_valid() function returns false, or if the
 * format is invalid (not colons) we set the fail-flag.
 *
 * With this implementation, we will never assign an
 * incorrect value to the 'time' variable.
 */
std::istream &operator>>(std::istream &is, Time &time);

#endif