/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#ifndef _UDPSOCKET_H_
#define _UDPSOCKET_H_


#include <netinet/in.h>
#include <string>
using namespace std;	
class UDPsocket {
 public:
  static void set_fd_nonblock(int fd);
  static void set_fd_sigio(int fd);
 public:
  void set_fd_nonblock() { set_fd_nonblock(socket_fd); }
  void set_fd_sigio() { set_fd_sigio(socket_fd); }

  static const int MAXMESG= 4096;

  int			socket_fd;
  struct sockaddr_in	serv_addr;
  UDPsocket() { socket_fd= -1; }
  bool init_socket_fd(int port= 0);
  bool init_serv_addr(const char* host, int port);
  bool send_msg(const string buf);
  bool recv_msg(char *buf, int & len, bool redirect= false);
  void close_socket_fd();
};

#endif
