
#ifndef INTERVAL_H
#define INTERVAL_H
#include<ostream>

struct Interval {
    long long min;
    long long max;

    long long mid() const {
        return (min + max) / 2;
    }

    bool operator<(const Interval& other) const {

    if (min != other.min) return min < other.min;
    return max < other.max; 
    }

    bool operator>(const Interval& other) const {

    if (min != other.min) return min > other.min;
    return max > other.max; 
    }

    friend std::ostream& operator<<(std::ostream &out, const Interval &I){
        out<<"("<<I.min<<"-"<<I.max<<")";
        return out;
    }
};

#endif