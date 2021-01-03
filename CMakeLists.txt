cmake_minimum_required(VERSION 3.17)
project(Demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        Demo main.cpp
        src/SyncLock.cpp
        src/RandomNumber.cpp/
        src/AsyncThread.cpp
        src/permutation/Factorial.cpp
        src/OperatorOverwrite.cpp
)