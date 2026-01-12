#ifndef SHARE_H
#define SHARE_H

#include <iostream>
#include <string>
#include <vector>

class Share {
public:
    std::string name;
    double startValue;
    double variance;
    double price_change;
    double expected_return;
    std::vector<int> shares; 
    int strategy;

    Share(std::string n, double s, double v, double p, double e, std::vector<int> sh, int strat) 
        : name(n), 
          startValue(s), 
          variance(v),   
          price_change(p), 
          expected_return(e), 
          shares(sh),       
          strategy(strat)   
    {}
};

#endif 