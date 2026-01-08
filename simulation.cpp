#include "include/simulation.h" 
#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <fstream>
#include <cmath>
#include <numeric>

// Function to compute the error function's inverse
double erfinv(double x) {
    if (x >= 1) return INFINITY;
    if (x <= -1) return -INFINITY;
    
    double a = 0.147; 
    double ln = std::log(1 - x * x);
    double lna = ln / 2 + 2 / (M_PI * a) + (ln / a) / 2;
    double s = std::sqrt(std::sqrt(lna * lna - ln / a) - lna);

    return (x < 0) ? -s : s;
}

// Inverse transform sampling for normal distribution
double norminv(double p, double mu, double sigma) {
    return mu + sigma * sqrt(2) * erfinv(2 * p - 1);
}


// The following source was used for the geometric brownian motion simulation:
// https://github.com/0xnu/sps_gbm_ef/blob/main/README.md
// This function is further explained in the ReadMe.md file provided
std::vector<double> geometric_brownian_motion(
    double initial_value,
    double variance,
    double years,
    double expected_return)
    {
    // daily steps -> there are approximately 252 trading days in a year (not 365)  
    double dt = 1.0 / 252.0;                     
    int N = static_cast<int>(years / dt + 1);

    double sigma = std::sqrt(variance);

    std::vector<double> S(N + 1);
    S[0] = initial_value;

    // Noise generation here
    std::default_random_engine generator(std::random_device{}());
    std::normal_distribution<double> normal(0.0, 1.0);


    for (int i = 1; i <= N; ++i) {
        double dW = normal(generator) * std::sqrt(dt);

        S[i] = S[i - 1] * std::exp(
            (expected_return - 0.5 * sigma * sigma) * dt + sigma * dW
        );
    }

    return S;
}


// Function to simulate stock prices using Exponentioal Moving Average (EMA) and Markov Chain
std::vector<double> markov_chain(double initial_value, double variance, double years, double expected_return) {
    std::vector<double> y;
    y.push_back(initial_value);
    
    int days = static_cast<int>(round(252 * years));
    std::vector<double> EMA(days+1);
   
    for (int t = 0; t <= days; ++t) {
        EMA[t] = pow(1 + expected_return, t / 252.0) * initial_value;
    }

    // std::default_random_engine generator;
    // std::normal_distribution<double> noise_distribution(0.0, sqrt(variance));
    
    std::random_device rd; // Obtain random number from hardware
    std::default_random_engine generator(rd()); // Seed the generator
    std::normal_distribution<double> noise_distribution(0.0, sqrt(variance));
    // std::lognormal_distribution<double> noise_distribution(0, sqrt(variance));


    for (double ema : EMA) {
        double std_dev = sqrt(variance);
        // double p = static_cast<double>(rand()) / RAND_MAX; // Uniform random

        std::random_device rd; // Obtain random number from hardware
        std::default_random_engine generator(rd()); // Seed the generator

        // Create a uniform distribution between 0.0 and 1.0
        std::uniform_real_distribution<double> distribution(0.0, 1.0);

        // Generate a random number
        double p = distribution(generator);        
        // The average is weighted so the volatility corresponds approximately to the variance
        double next_value = (norminv(p, ema, std_dev) + 19*y.back()) / 20; 
        y.push_back(next_value);
    }

    return y;
}


// Function to simulate stock prices directly
std::vector<double> simulate_stock(double initial_value, double variance, double expected_return, double years, int model) {
    std::vector<double> values;
    values.push_back(initial_value);
    
    // choice of model to simulate the stock market:
    if (model == 1){
        return markov_chain(initial_value, variance, years, expected_return);
    } else {
        return geometric_brownian_motion(initial_value, variance, years, expected_return);
    }

}


void strategy(InputValues &in) {
    std::map<std::string, std::vector<double>> data;

    int strategy = in.strategies;

    // Count the total number of entries in in.shares
    int total_number_of_shares = static_cast<int>(in.shares.size());

    if (strategy == 1) {
        // Uniform distribution:
        double distribution = 1.0 / total_number_of_shares; // Ensure double precision
        in.custom_allocation.clear(); // Clear previous allocations
        in.custom_allocation.resize(total_number_of_shares, distribution); // Fill vector with 'distribution'

    }

    if (strategy == 2) {
        // Conservative minimize risk:
        double sum = std::accumulate(in.variance.begin(), in.variance.end(), 0.0);
        
        // Prevent division by zero
        if (sum != 0) {
            double norm = 1.0 / sum;
            in.custom_allocation.clear();
            in.custom_allocation.resize(in.variance.size()); 

            for (size_t i = 0; i < in.variance.size(); ++i) {
                in.custom_allocation[i] = in.variance[i] * norm; 
        }
        } 
        else{
            std::cerr << "Error: The sum of the variance values is zero. Unable to normalize allocations." << std::endl;
        }
        }
    

    if (strategy == 3) {
    // Potential high risk, optimize by expected return, could be part of a long term investment strategy:
    double sum = std::accumulate(in.expected_return.begin(), in.expected_return.end(), 0.0);
    
        // Prevent division by zero
        if (sum != 0) {
            double norm = 1.0 / sum;
            in.custom_allocation.clear(); // Clear previous allocations
            in.custom_allocation.resize(in.expected_return.size()); // Resize the vector to hold new values

                for (size_t i = 0; i < in.expected_return.size(); ++i) {
                    in.custom_allocation[i] = in.expected_return[i] * norm; // Multiply each element by the normalization factor
                }
        } else{
            std::cerr << "Error: The sum of the expected return values is zero. Unable to normalize allocations." << std::endl;
        }
    }
}


void simulate_wallet() {
    InputValues in;
    std::map<std::string, std::vector<double>> data;
    double years = in.time_steps / 252.0;
    double total_profit = 0.0;

    strategy(in);
    
    std::vector<double> sum_of_stock_shares(in.time_steps + 2);

    for (size_t i = 0; i < in.shares.size(); ++i) {
        double initial_value = in.initial_value[i];
        double variance = in.variance[i];
        double expected_return = in.expected_return[i];  
        
        double money_invested = in.fund * in.custom_allocation[i];
        double amount_of_stocks = money_invested / initial_value;

        std::vector<double> stock_simulation = simulate_stock(initial_value, variance, expected_return, years, in.model);
        for (size_t j = 0; j < stock_simulation.size(); ++j) {
            stock_simulation[j] *= amount_of_stocks;
            sum_of_stock_shares[j] = stock_simulation[j] + sum_of_stock_shares[j];
        }

        data[in.shares[i]] = stock_simulation;
    }

    data[" Total Capital"] = sum_of_stock_shares;

    std::vector<double> profit_of_stock_shares = sum_of_stock_shares;

    for (size_t j = 0; j < sum_of_stock_shares.size(); ++j) {
        sum_of_stock_shares[j] = (sum_of_stock_shares[j]-in.fund)/in.fund * 100;
        profit_of_stock_shares[j] -=in.fund;
    }

    data[" Profit (€)"] = profit_of_stock_shares;
    data[" Profit (%)"] = sum_of_stock_shares;

    // Calculate profit
    double final_value = 0.0;
    for (auto& entry : data) {
        final_value += entry.second.back();
    }
    total_profit = final_value - in.fund;

    // Write output to CSV file
    std::ofstream output_file("output.csv");
    output_file << "Time,";
    for (const auto& entry : data) {
        output_file << entry.first << ",";
    }
    // output_file << "Profit (€),Profit (%)\n";

    // Find the maximum number of simulation steps
    size_t max_steps = 0;

        for (const auto& entry : data) {
        max_steps = std::max(max_steps, entry.second.size());
    }
    output_file << "\n";  

    // Write time steps and corresponding stock values
    for (size_t step = 0; step < max_steps; ++step) {
        output_file << step << ",";
        for (const auto& entry : data) {
            if (step < entry.second.size())
                output_file << entry.second[step] << ",";
            else
                output_file << "0,";  
        }
        
        // output_file << total_profit << ",";
        // output_file << (total_profit / in.fund) * 100 << "\n";  
        output_file << "\n";  

    }

    output_file.close(); 
}

int main() {
    simulate_wallet(); 
    return 0;
}
