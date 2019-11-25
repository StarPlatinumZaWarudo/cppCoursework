cmake_minimum_required(VERSION 3.15)
project(cppCW)

set(CMAKE_CXX_STANDARD 17)

add_executable(avCW source/main.cpp source/vote.cpp source/election.cpp source/vote.h source/election.h)