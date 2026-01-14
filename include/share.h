#ifndef SHARE_H
#define SHARE_H

#include <iostream>
#include <string>
#include <vector>

class Share {
public:
    std::vector<std::string> name = {"Google", "Amazon", "Tesla", "Ferrero"}; 
    std::vector<double> initial_value = {10.34, 1.92, 5.23, 4.01};
    std::vector<double> variance  = {0.04, 0.035, 0.03, 0.045}; 
    std::vector<double> price_change = {0,0,0,0}; 
    std::vector<double> expected_return = {0.10, 0.05, 0.2, 0.25}; 

    // Share(const std::vector<std::string>& n,
    //       const std::vector<double>& i, const std::vector<double>& v,
    //       const std::vector<double>& p, const std::vector<double>& e)
    //     : name(n),
    //       initial_value(1), 
    //       variances(v), 
    //       price_change(p), 
    //       expected_return(e) 
    // {}
};

#endif // SHARE_H
