#pragma once
#include <string>

class Candle {
    std::string date;
    double open, high, low, close;
    double volume;
public:
    Candle(std::string d, double o, double h, double l, double c,double v=0.0) : date(d), open(o), high(h), low(l), close(c), volume(v) {}
    double getOpen() const { return open; }
    double getHigh() const { return high; }
    double getLow() const { return low; }
    double getClose() const { return close; }
    double getVolume() const { return volume; }
    std::string getDate() const { return date; }

};
