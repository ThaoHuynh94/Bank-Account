cmake_minimum_required(VERSION 3.27)
project(BankProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankProject main.cpp
        Bank.h
        Bank.cpp
        Saving.h
        Saving.cpp
        Checking.h
        Checking.cpp

)
