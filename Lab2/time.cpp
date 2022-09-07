#include "time.h"
#include <sstream>
#include <iomanip>
using namespace std;

bool is_valid(Time const &time) {
    return ((time.hour < 24 && time.hour >= 0) && 
            (time.min < 60 && time.min >= 0) && 
            (time.sec < 60 && time.sec >= 0));
};

bool is_am(Time const &time) {
    return (time.hour < 12);
};

string to_string(Time const &time, bool twelve_format) {
    string append{};  
    bool pm{false}; 
    ostringstream oss{};

    if (twelve_format) {
        if (is_am(time)) {
            append = " am";
        } else {
            append = " pm";
            pm = true; 
        }
    }
    oss << setfill('0') 
    << setw(2) << time.hour - (12*pm) << ":"  
    << setw(2) << time.min << ":" 
    << setw(2) << time.sec;

    return oss.str();
}

Time operator+(Time const &time, int n) {
    return timeAdd(time, n);
}

Time operator-(Time const &time, int n) {
    return timeSub(time, n);
}

Time operator++(Time const &time) {    
    return timeAdd(time, 1);
}

Time operator++(Time const &time, int n) {    
    return timeAdd(time, 1);
}

Time operator--(Time const &time) {
    return timeSub(time, 1);
}

Time operator--(Time const &time, int n) {
    return timeSub(time, 1);
}

bool operator<(Time const &time1, Time const &time2) {
    if (time1.hour < time2.hour) {
        return true;
    } else if (time1.hour == time2.hour) {
        if (time1.min < time2.min) {
            return true;
        } else if (time1.min == time2.min) {
            if (time1.sec < time2.sec) {
                return true;
            } else if (time1.sec == time2.sec) {
                return false;
            }
        }
    }
    return false;
}

bool operator>(Time const &time1, Time const &time2) {
    if (time1.hour > time2.hour) {
        return true;
    } else if (time1.hour == time2.hour) {
        if (time1.min > time2.min) {
            return true;
        } else if (time1.min == time2.min) {
            if (time1.sec > time2.sec) {
                return true;
            } else if (time1.sec == time2.sec) {
                return false;
            }
        }
    }
    return false;
}

bool operator==(Time const &time1, Time const &time2) {
    if (time1 < time2 || time1 > time2) {
        return false;
    } 
    return true;
}

bool operator!=(Time const &time1, Time const &time2) {
    if (time1 == time2) {
        return false;
    }
    return true;
}

bool operator>=(Time const &time1, Time const &time2) {
    if (time1 > time2 || time1 == time2) {
        return true;
    }
    return false;
}

bool operator<=(Time const &time1, Time const &time2) {
    if (time1 < time2 || time1 == time2) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream &os, Time const &time) {
    os << to_string(time, 0);
    return os;
}

istream& operator>>(istream &is, Time &time) {
    char c{};
    is >> time.hour >> c >> time.min >> c >> time.sec;
    if (is_valid(time)) {
        is.setstate(ios_base::goodbit);
    } else {
        is.setstate(ios_base::failbit);
    }
    is.clear();
    return is;
}


/*  Helper functions for adding and subtracting time,
    used in the functions for the operators 
    "+", "-", "++" and "--".
*/
Time timeAdd(Time const &time, int n) {
    Time time_tmp{time};
    time_tmp.sec += n;
    time_tmp.min += (time_tmp.sec / 60);
    time_tmp.sec = time_tmp.sec % 60;
    time_tmp.hour += (time_tmp.min / 60);
    time_tmp.min = time_tmp.min % 60;
    time_tmp.hour = time_tmp.hour % 24;
    return time_tmp;
}

Time timeSub(Time const &time, int n) {
    Time time_tmp{time};
    time_tmp.sec -= (n % 60);
    time_tmp.min -= ((time_tmp.sec + n) / 60) % 60;
    time_tmp.hour -= ((time_tmp.sec + n) / 60) / 60;

    if (time_tmp.sec < 0) {
        time_tmp.min--;
        time_tmp.sec += 60;
    }
    if (time_tmp.min < 0) {
        time_tmp.hour--;
        time_tmp.min += 60;
    }
    while (time_tmp.hour < 0) {
        time_tmp.hour += 24;
    }
    return time_tmp;   
}

 