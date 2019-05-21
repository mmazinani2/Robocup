/************************************
Create by
Mohammad Mazinani
Mohammad Ali Kamkar
Mehdi Torshani
*************************************/
#include "udpsocket.h"

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>

#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#ifdef MEMSET
#define bzero(a, b) memset(a, 0, b)
#endif

bool UDPsocket::init_socket_fd(int port) {
  struct sockaddr_in cli_addr;
  int fd;
  if( (fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
    return false ;    
  }

  bzero((char *) &cli_addr, sizeof(cli_addr)) ;
  cli_addr.sin_family           = AF_INET ;
  cli_addr.sin_addr.s_addr      = htonl(INADDR_ANY) ;
  cli_addr.sin_port             = htons(port) ;
   
  if (bind(fd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0){
    return false ; 
  }
  socket_fd= fd;
  return true;
}

bool UDPsocket::init_serv_addr(const char* host, int port) {
 struct hostent        *host_ent ;
 struct in_addr      *addr_ptr ;
 
 if((host_ent = (struct hostent *)gethostbyname(host)) == NULL) {
      /* Check if a numeric address */
   if((int)inet_addr(host) == -1){
     return false;
   }
 }
 else {
   addr_ptr = (struct in_addr *) *host_ent->h_addr_list ;
   host = inet_ntoa(*addr_ptr) ;
 }

  bzero((char *) &serv_addr, sizeof(serv_addr)) ;
  serv_addr.sin_family		= AF_INET ;
  serv_addr.sin_addr.s_addr	= inet_addr(host) ;
  serv_addr.sin_port		= htons(port) ;
  return true;
}

bool UDPsocket::send_msg(const string buf) {
  const char *st2 = buf.c_str();	
  if (!st2) return false;
  int res = sendto(socket_fd, st2, strlen(st2)+1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (res != (strlen(st2)+1) ) {
    return false ;
  }

  return true;
}


bool UDPsocket::recv_msg(char *buf, int & len, bool redirect) {
  unsigned int addr_len ;
  struct sockaddr_in    recv_addr ;
      
  addr_len = (unsigned int) sizeof(recv_addr) ;
  len = recvfrom(socket_fd, buf, MAXMESG, 0,(struct sockaddr *)&recv_addr, &addr_len);
  if(len < 0) {
    if( len == -1 && errno == EWOULDBLOCK){
    }
    len = 0;
    buf[0]= '\0';
    return false ;
  }
  buf[len] = '\0' ;

  if ( redirect  
       && serv_addr.sin_addr.s_addr == recv_addr.sin_addr.s_addr 
       && serv_addr.sin_port != recv_addr.sin_port ) { 
    serv_addr.sin_port = recv_addr.sin_port ; 
    }
  return true;
  
}

void UDPsocket::set_fd_nonblock(int fd) {


  if ( fcntl( fd , F_SETOWN, getpid()) == -1) 
    std::cout << "\nfcntl returns -1";
  else {
    int val = fcntl(fd, F_GETFL, 0) ;

#if 1 
    val |= O_NDELAY ;
#else
    val |= O_NONBLOCK ;
#endif
    fcntl(fd, F_SETFL, val) ;
  }
}

void UDPsocket::set_fd_sigio(int fd) {


  if ( fcntl( fd , F_SETOWN, getpid()) == -1) 
   std::cout << "\nfcntl returns -1";
  else {
    //cout << "\nfcntl returns != -1";
    int val = fcntl(fd, F_GETFL, 0) ;

    val |= FASYNC;
    fcntl(fd, F_SETFL, val) ;
  }
}

void UDPsocket::close_socket_fd() {
  close(socket_fd);
}


#if 0
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/***************  T  E  S  T**************************************************/
main() {
  char buf[MAXMESG];
  int len;
  UDPsocket sock;
  cout << "\ninit_socket_fd = " << sock.init_socket_fd();
  cout << "\ninit_serv_addr = " << sock.init_serv_addr("robocup3",6000);
  cout << "\nsend_msg       = " << sock.send_msg("(init BS2k (version 5.25))");
  cout << "\nrecv_msg       = " << sock.recv_msg(buf,len);
  cout << "\nbuf= " << buf;
  sock.send_msg("(dash 100)");
  sock.close_socket_fd();
}
#endif 

