#include <boost/asio.hpp>

using boost::asio::ip::tcp;

boost::asio::awaitable<void> echo(tcp::socket peer_socket,
                                  tcp::acceptor acceptor);

int MyEchoServer();
