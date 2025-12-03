cmake_minimum_required(VERSION 3.10)
project(StockSimulation)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    simulation.cpp 
)

add_executable(stock_simulation ${SOURCES})
