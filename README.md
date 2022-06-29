# How to Use C++20 Coroutines for Networking

## Example Code

This repository contains the example code that accompanies [my](http://www.james-pascoe.com)
 [ACCU 2022](https://accu.org/conf-news/2022/2022-01-21-accu2022schedulepubished/) talk
[How to Use C++20 Coroutines for Networking](https://accu.digital-medium.co.uk/session/how-to-use-c20-coroutines-for-networking/) ([slides](https://jamespascoe.github.io/accu2022)).

 This repository consists of four sub-directories:

1. [echo_server](https://github.com/jamespascoe/accu2022-example-code/tree/master/echo_server) | [screen_capture](https://jamespascoe.github.io/accu2022/#/5/3)
    1. [Blocking Echo Server](https://github.com/jamespascoe/accu2022-example-code/blob/master/echo_server/echo_server_blocking.cpp)
    2. [Asynchronous Echo Server](https://github.com/jamespascoe/accu2022-example-code/blob/master/echo_server/echo_server_async.cpp)
    3. [Coroutine Echo Server](https://github.com/jamespascoe/accu2022-example-code/blob/master/echo_server/echo_server_coroutine.cpp)
2. [lua_chat](https://github.com/jamespascoe/accu2022-example-code/tree/master/lua_chat/lua_chat.lua) | [screen_capture](https://jamespascoe.github.io/accu2022/#/6/7)
3. [generator](https://github.com/jamespascoe/accu2022-example-code/tree/master/generator/card_dealer.cpp)
4. [co_chat](https://github.com/jamespascoe/accu2022-example-code/tree/master/co_chat/co_chat.cpp) | [screen_capture](https://jamespascoe.github.io/accu2022/#/8/2)

With the exception of the [generator](https://github.com/jamespascoe/accu2022-example-code/tree/master/generator/) example (which has build instructions in the [code](https://github.com/jamespascoe/accu2022-example-code/tree/master/generator/card_dealer.cpp), each code base has an accompanying video to demonstrate how its built and used. For details of the supported build environments / supported libraries, see [here](https://jamespascoe.github.io/accu2022/#/4/0/6).

# Msys2
With a Windows version (14.2 is for Visual Studio 2019) of boost installed in D:\Code\boost_1_79_0
```
cd echo_server

g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror echo_server_blocking.cpp  -o blocking  -lws2_32
g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror echo_server_async.cpp     -o async     -lws2_32 -lwsock32
g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror -fcoroutines -std=c++20 echo_server_coroutine.cpp -o coroutine -lws2_32 -lwsock32
```

# Ubuntu
Installing boost on Ubuntu
```
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev
wget -O boost_1_79_0.tar.bz2 https://sourceforge.net/projects/boost/files/boost/1.79.0/boost_1_79_0.tar.bz2/download
# wget -O boost_1_79_0.tar.gz https://sourceforge.net/projects/boost/files/boost/1.79.0/boost_1_79_0.tar.gz/download
tar xzvf boost_1_79_0.tar.gz
cd boost_1_79_0/
./bootstrap.sh --prefix=/usr/
./b2
sudo ./b2 install
```

Lua: `sudo apt-get install lua5.4 liblua5.4-dev unzip`

# Luarocks
```
wget https://luarocks.org/releases/luarocks-3.9.0.tar.gz
tar zxpf luarocks-3.9.0.tar.gz
cd luarocks-3.9.0
./configure && make && sudo make install
```

## luasocket
```
sudo luarocks install luasocket
```



Build
```
cd echo_server
g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror echo_server_blocking.cpp  -o blocking;
g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror echo_server_async.cpp     -o async;
g++ -I /d/Code/boost_1_79_0/ -L /d/Code/boost_1_79_0/lib64-msvc-14.2/boost_thread-vc142-mt-gd-x64-1_79.lib -Wall -Werror -fcoroutines -std=c++20 echo_server_coroutine.cpp -o coroutine;
```

