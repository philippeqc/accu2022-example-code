cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
project(testEchoServer VERSION 0.1.0)


# include_directories(${SOURCE_DIR}/include)

add_executable(testEchoServer
  ${PROJECT_SOURCE_DIR}/EchoServer_test.cpp
)

target_include_directories(testEchoServer PUBLIC
  ../../my_echo_server
)

add_dependencies(testEchoServer
    echoServer
)

# These tests can use the Catch2-provided main
target_link_libraries(
  testEchoServer
    LINK_PUBLIC
    Catch2::Catch2WithMain
    echoServer 
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(testEchoServer)
