//
// echo_server_coroutine.cpp
// -------------------------
//
// g++-11 -I/usr/local/boost_1_78_0/include -fcoroutines -std=c++20
// -Wall -Werror echo_server_coroutine.cpp -o coroutine -l pthread
//

#include <boost/asio/experimental/as_tuple.hpp>

#include <iostream>

#include "my_echo_server_coroutine.h"

using boost::asio::buffer;
using boost::asio::detached;
using boost::asio::io_context;
using boost::asio::use_awaitable;
using boost::asio::experimental::as_tuple;
using boost::system::error_code;

class IAcceptor {
public:
  boost::asio::awaitable<void>
  async_accept(tcp::acceptor &acceptor, tcp::socket &peer_socket
               //,boost::asio::use_awaitable_t<> &my_use_awaitable
  ) {
    co_await acceptor.async_accept(peer_socket, use_awaitable);
  }
};

boost::asio::awaitable<void> echo(tcp::socket peer_socket,
                                  tcp::acceptor acceptor) {
  std::array<char, 1000> buf;

  for (;;) {
    IAcceptor iAcceptor;
    // co_await acceptor.async_accept(peer_socket, use_awaitable);
    // iAcceptor.async_accept(acceptor, peer_socket,
    // use_awaitable);
    co_await iAcceptor.async_accept(acceptor, peer_socket);

    for (;;) {
      auto [error, len] = co_await peer_socket.async_read_some(
          buffer(buf), as_tuple(use_awaitable));
      if (error == boost::asio::error::eof)
        break;

      co_await async_write(peer_socket, buffer(buf, len),
                           use_awaitable);
    }

    peer_socket.close();
  }
}

int MyEchoServer() {
  try {
    io_context ctx;

    tcp::socket socket(ctx);
    tcp::acceptor acceptor(ctx, tcp::endpoint(tcp::v4(), 6666));

    co_spawn(ctx, echo(std::move(socket), std::move(acceptor)),
             detached);

    ctx.run();
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
