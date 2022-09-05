#include "time.h"
//#include <sstream>
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
    /* Var for appending am or pm to time string. */
    string append{};  

    /* Var for formatting time to either 12- or 24-hour clock, depending on outcome of is_am(). */ 
    bool pm{false}; 

    /* Var to "print" time to a string. */
    std::ostringstream oss{};

    /* If input bool is true */
    if (twelve_format) {
        /* If the time is am */
        if (is_am(time)) {
            append = " am";
        } else {
            append = " pm";
            /* Set "pm" to true for later use. See below. */
            pm = true; 
        }
    }
    /* 
    If "pm" is true, pm == 1, and the "print" will be time.hour - 12, i.e. 12-hour clock format. 
    If "pm" is false, p == 0, and the "print" will be time.hour - 0, i.e. 24-hour clock format. 
    */
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
    } else if (time1.min < time2.min) {
        return true;
    } else if (time1.sec < time2.sec) {
        return true;
    }
    return false;
}

bool operator>(Time const &time1, Time const &time2) {
    if (time1.hour > time2.hour) {
        return true;
    } else if (time1.min > time2.min) {
        return true;
    } else if (time1.sec > time2.sec) {
        return true;
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

/*string operator>>(Time const &time) {

}*/

// Helper functions

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

 