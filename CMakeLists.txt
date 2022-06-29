cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
project(my_co VERSION 0.1.0)


add_subdirectory(my_echo_server)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test/testEchoServer)
endif()

# ==========================================
add_executable(
  echoServerRunner
  main.cpp
)

target_include_directories(echoServerRunner PUBLIC
  ./my_echo_server
)

target_link_libraries(
    echoServerRunner
    LINK_PUBLIC
    echoServer 
)
