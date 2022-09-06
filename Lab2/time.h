// Header file. Contains the declarations of functions that should be available in your module. 

#ifndef TEST_H 
#define TEST_H 

#include <string>

struct Time {
    int hour{};
    int min{};
    int sec{};
};

bool is_valid(Time const &time);

bool is_am(Time const &time);

std::string to_string(Time const &time, bool twelve_format);

Time operator+(Time const &time, int n);

Time operator-(Time const &time, int n);

Time operator++(Time const &time);

Time operator++(Time const &time, int n);

Time operator--(Time const &time);

Time operator--(Time const &time, int n);

bool operator<(Time const &time1, Time const &time2);

bool operator>(Time const &time1, Time const &time2);

bool operator==(Time const &time1, Time const &time2);

bool operator!=(Time const &time1, Time const &time2);

bool operator>=(Time const &time1, Time const &time2);

bool operator<=(Time const &time1, Time const &time2);

Time timeAdd(Time const &time, int n);

Time timeSub(Time const &time, int n);

#endif