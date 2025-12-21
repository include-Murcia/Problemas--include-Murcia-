
#ifndef INTERVAL_H
#define INTERVAL_H
#include<ostream>

struct Interval {
    long long min;
    long long max;

    bool operator<(const Interval& other) const { //Sobrecarga de operador para saber si el intervalo es menor

    if (min != other.min) return min < other.min;
    return max < other.max; 
    }

    bool operator>(const Interval& other) const { //Sobrecarga de operador para saber si el intervalo es mayor

    if (min != other.min) return min > other.min;
    return max > other.max; 
    }

    friend std::ostream& operator<<(std::ostream &out, const Interval &I){ // Sobrecarga de operador para impimir el intervalo
        out<<"("<<I.min<<"-"<<I.max<<")";
        return out;
    }
};


#endif
