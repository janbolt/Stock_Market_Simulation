# TODO List for Project Stock Market Simulation

<!-- # Sprint 1 -->

<!-- 
## Features
- [ ] Implement user authentication #todo
- [x] Design database schema #done

## Bugs
- [ ] Fix issue with login timeout #in-progress -->


## Sprint 1
In the first sprint, at the beginning of the simulation, the wallets will be initialized with a limited amount of market shares. The market will evolve and modify the amount of money in the wallets. In this phase, it will be possible to choose between two types of investment 'strategies', a low-risk/low-return strategy and a high-risk strategy with more chance of higher income.





### Definition of "done" 
- User will be able to input:
    - <span style="color:green;">[x]</span> Funds to invest in the market
    - <span style="color:green;">[x]</span> Strategies (e.g. percentages of available funds used on different shares, the user can choose among different possibilities)
    - <span style="color:green;">[x]</span> Shares (e.g. array of strings representing the name of the company)
    - <span style="color:green;">[x]</span> Shares' statistical parameters (e.g. change in stock market, standard deviation of returns, expected return, all float/double numbers)


#### Example of input
    "input": {
        "fund": 1000000, // amount of money to invest for one wallet
        "strategies": 1, // option of multichoice menu for numbered strategies for one wallet
                         // A "strategy" is a procedure to distribute invested money (fund) on shares
                         // e.g. 50% on low-risk shares, 30% on mid-risk shares, 20% on high-risk shares
        "shares": ["Google", "Amazon", "Tesla", "Ferrero"], // array of strings, each string is the company to which the shares refer
        "variance": [3.1415927, 1.5707963, 6.2831853, 1.0471975], // statistical parameters for each share
        "price_change": [-4.27, 2.75, 0.23, 5.02], // statistical parameters for each share
        "expected_return": [0.10, 0.05, 0.2, 0.25], // statistical parameters for each share (percentage)
        "initial_value": [10.34, 1.92, 5.23, 4.01] // initial values of the shares
    }


- Output will be:
    - <span style="color:green;">[x]</span> Trends of the market shares (e.g. a float/double data structure which can register the fluctuations) at the end of the market simulation.
    - <span style="color:green;">[x]</span> Funds available on the wallets, or percentage of income/loss, at the end of the wallet investments simulation.

#### Example of output
    "output": {
        "trend_google": [10.34, 9.84, 11.05, 13.22, 25.85, ...], // trends for each share
        "trend_amazon": [1.92, 1.89, 1.85, 1.95, 1.99, ...], // trends for each share
        "trend_tesla": [5.23, 25.23, 24.78, 17.12, 4.56, ...], // trends for each share
        "trend_ferrero": [4.01, 4.02, 4.04, 4.51, 5.01, ...], // trends for each share
        ...,
        "final_funds": 1014593.52 // final amount of money in the wallet
                                    // alternatively: "income": 0.23, percentage of income at the end of the simulation
    }

### Further improvements
The listed tasks are not strictly required for the assignment/sprint!
- <span style="color:orange;">[ _ ]</span> Allow users to give direct inputs eather in the form of a seperate .json file or using input statetements during runtime.
- <span style="color:orange;">[ _ ]</span> Replace CSV file by json file to store outputs.
- <span style="color:orange;">[ _ ]</span> A function to visualize the plots (by using matplotlib as an example).
<!-- - <span style="color:orange;">[ _ ]</span> 
- <span style="color:orange;">[ _ ]</span>
- <span style="color:orange;">[ _ ]</span> -->

## Sprint 2
The objective of the second sprint is, thanks to the use of object-oriented programming, to create different classes for shares, wallets, strategies.Through this code refactoring, it will be possible to create interactions between the market simulation and the wallets simulation. A massive shares purchase in the market will consequentially change the value of the shares themselves. The statistical data concerning the recent market fluctuations and the quotes will be registered, and they can be utilized in the single investment strategies.

### Definition of "done"</span>
- <span style="color:red;">[ _ ]</span> The market model and the investment model were successfully converted to object-oriented models

#### Example of possible class implementation

    "Share": {
        "name": "string",
        "startValue": "initial_market_value",
        "variance": "statParam1",
        "price_change": "statParam2",
        "expected_return": "statParam3"
    }

    "Wallet": {
        "name": "string",
        "funds": "float",
        "shares": "array(int)",
        "strategy": "int".
    }

    "Strategy": {
        "id": "int",
        "fppsr": "array(double)" //fppsr = funding percentage per share risk
    }

- <span style="color:red;">[ _ ]</span> The simulations were correctly interconnected, i.e., there is a cause-effect relationship between purchases and market values: for example, if many wallets buy the same share, this share is affected by this in the form of a rise in its value.

This can be done, for example, by inserting as input of the simulation a new object with information on the number of purchases for each share, and using this information to modify the fluctuations of the shares.



## Sprint 3

In the final sprint, the code performance will be evaluated and improved. To do this, bulk tests will be executed. Finding potential bottlenecks and investigating optimization options for the code, including loop transformations, STL containers, vectorization options and complexity analysis to find potential improvements will also be part of this sprint.

### Definition of "done"
- <span style="color:red;">[ _ ]</span> A file `performance.md` presents the observations from the performance analysis
- <span style="color:red;">[ _ ]</span> The same file presents at least one different optimization technique you applied, with the observable performance effects.
