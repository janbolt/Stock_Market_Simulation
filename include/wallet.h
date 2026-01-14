#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>

class Wallet {
public:
    // in each vector at position i we have another wallet in units Wallet.units[i][j] we access amount of shares for share i -> i representing share_id
    std::vector<std::string> name = {"John", "Nick", "Sandra"};
    std::vector<double> cash_savings = {1000, 1000, 1000};
    std::vector<std::vector<double>> units = {{10,10,10,10}, {5,10,4,5},{0, 100,40,50}};   
    std::vector<int> strategy_id = {3,2,1};
    std::vector<int> trading_frequency = {12, 3, 90}; // amount of days where a trade was executed in a year
    // std::vector<double> monthly_savings_plan = {100, 1000, 2000}; // monthly investments while there is enough cash savings -> allocation according to strategies

    void print() const;

    // Wallet(const std::vector<std::string>& n, const std::vector<double>& funds, 
    //        const std::vector<int>& strats, int numShares)
    //     : name(n), cash(funds), units(funds.size(), std::vector<double>(numShares, 0.0)), 
    //       strategy_id(strats) {}
};

#endif