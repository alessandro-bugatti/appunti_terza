/**
* DatagramSocket: C++ Class for UDP communications for Windows/Unix
* @author Glenn Butcher (original author), Alessandro Bugatti
* @date 8/27/2010, 08/05/2024 (last update)
*/

#ifndef DATAGRAMSOCKET_H_INCLUDED
#define DATAGRAMSOCKET_H_INCLUDED


#ifdef WIN32
#include <winsock2.h>
typedef int socklen_t;
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#define TRUE 1
#define FALSE 0
#endif


//Simple socket class for datagrams.  Platform independent between
//unix and Windows.
class DatagramSocket
{
private:
#ifdef WIN32
    WSAData wsaData;
    SOCKET sock;
#else
    int sock;
#endif
    long retval;
    sockaddr_in outaddr;
    char ip[30];
    char received[2048];


public:
    DatagramSocket(unsigned int port, const char* address, bool blocking = true, bool Datagram = true, bool reusesock = true);


    ~DatagramSocket();

    long receive(char* msg, int msgsize);
    char* received_from();
    long send(const char* msg, int msgsize);
    long sendTo(const char* msg, int msgsize, const char* name);

    static int getAddress(const char * name, char * addr);
    const char* getAddress(const char * name);

};



#endif // DATAGRAMSOCKET_H_INCLUDED
