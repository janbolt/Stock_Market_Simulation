#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include <map>

// Structure to hold input values for the stock simulation
struct InputValues {
    int fund = 4000;
    int strategies = 2; // 1-4 strategies -> more info in the ReadMe.md file
    std::vector<double> custom_allocation = {0.25, 0.25, 0.25, 0.25}; // custom allocation -> this will only be accounted for if strategies != {1,2,3}
    std::vector<std::string> shares = {"Google", "Amazon", "Tesla", "Ferrero"};
    std::vector<double> variance = {0.04, 0.035, 0.03, 0.045}; // per year
    std::vector<double> expected_return = {0.10, 0.05, 0.2, 0.25}; // per year
    std::vector<double> initial_value = {10.34, 1.92, 5.23, 4.01}; // value of stock when purchased
    int time_steps = 252*1; // number of days, for n years -> 252 * n
    int model = 1; // 1 for markov chain with EMA. 2 for geometric brownian motion

    void print() const;
};

// for sprint 2 and 3 (for multiple files...): 
// std::vector<double> markov_chain(double initial_value, double variance, double years, double expected_return);
// std::vector<double> simulate_stock(double initial_value, double variance, double expected_return, double years);
// void simulate_wallet();

// double erfinv(double x);
// double norminv(double p, double mu, double sigma); 

#endif 
