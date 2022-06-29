cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
project(echoServer VERSION 0.1.0)


add_library(echoServer my_echo_server_coroutine.cpp)
FIND_PACKAGE(Boost 1.79.0 REQUIRED COMPONENTS system)
