#ifndef SHARE_H
#define SHARE_H

#include <iostream>
#include <string>
#include <vector>

class Share {
public:
    std::string name;
    double initial_value;
    double variance;
    double price_change;
    double expected_return;

    Share(std::string n, double s, double v, double p, double e) 
        : name(n), 
          initial_value(s), 
          variance(v),   
          price_change(p), 
          expected_return(e) 
    {}

};

#endif