#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include <map>

// Structure to hold input values for the stock simulation
struct InputValues {
    int fund = 4000;
    int strategies = 2;
    std::vector<double> custom_allocation = {0.25, 0.25, 0.25, 0.25};
    std::vector<std::string> shares = {"Google", "Amazon", "Tesla", "Ferrero"};
    std::vector<double> variance = {0.04, 0.035, 0.03, 0.045};
    std::vector<double> expected_return = {0.10, 0.05, 0.2, 0.25};
    std::vector<double> initial_value = {10.34, 1.92, 5.23, 4.01};
    int time_steps = 365*1;
    int model = 1;

    void print() const;
};

std::vector<double> markov_chain(double initial_value, double variance, double years, double expected_return);
std::vector<double> simulate_stock(double initial_value, double variance, double expected_return, double years);
void simulate_wallet();

double erfinv(double x);
double norminv(double p, double mu, double sigma); 

#endif 
