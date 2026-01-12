#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <string>
#include <vector>

class Wallet{
public:
    std::string name;
    double funds;
    std::vector<int> shares;
    int strategy;

    Wallet(std::string n, double f, int s) : name(n), funds(f), strategy(s) {}
};

#endif