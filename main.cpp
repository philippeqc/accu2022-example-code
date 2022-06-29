#include <iostream>

#include "my_echo_server_coroutine.h"

void say_hello(){
    std::cout << "Hello, from my_co!\n";
}

int main() {
    MyEchoServer();
}
