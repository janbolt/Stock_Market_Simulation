#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>

class Wallet {
public:
    // in each vector at position i we have another wallet in units Wallet.units[i][j] we access amount of shares for share i -> i representing share_id
    std::vector<std::string> name = {"John", "Sandra", "Nick"};
    std::vector<double> cash = {1000, 8987,9829};
    std::vector<std::vector<double>> units = {{5,10,4,5}, {5,10,4,5}, {5,10,4,5},{5,10,4,5}};   
    std::vector<int> strategy_id = {1,2,2,2};

    void print() const;

    // Wallet(const std::vector<std::string>& n, const std::vector<double>& funds, 
    //        const std::vector<int>& strats, int numShares)
    //     : name(n), cash(funds), units(funds.size(), std::vector<double>(numShares, 0.0)), 
    //       strategy_id(strats) {}
};

#endif