#include "DatagramSocket.h"

DatagramSocket::DatagramSocket(unsigned int port, const char* address,bool blocking,  bool broadcast, bool reusesock)
{
#ifdef WIN32
    retval = WSAStartup(MAKEWORD(2,2),&wsaData);
#endif

    sockaddr_in addr;
    sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

    //set up bind address
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    //set up address to use for sending
    memset(&outaddr,0,sizeof(outaddr));
    outaddr.sin_family = AF_INET;
    outaddr.sin_addr.s_addr = inet_addr(address);
    outaddr.sin_port = htons(port);

#ifdef WIN32
    bool bOptVal = true;
    int bOptLen = sizeof(bool);
#else
    int OptVal = 1;
#endif

    if (broadcast)
#ifdef WIN32
        retval = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<char *>(&bOptVal), bOptLen);
#else
    retval = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &OptVal, sizeof(OptVal));
#endif

    if (reusesock)
#ifdef WIN32
        retval = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&bOptVal), bOptLen);
#else
    retval = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &OptVal, sizeof(OptVal));
#endif

#ifdef WIN32
    if (!blocking) {
        u_long nMode = 1;
        ioctlsocket (sock, FIONBIO, &nMode);
    }
#else
    if (!blocking) {
        int flags = fcntl(sock, F_GETFL);
        fcntl(sock, F_SETFL, flags | O_NONBLOCK);
    }
#endif

    retval = bind(sock,reinterpret_cast<struct sockaddr *>(&addr),sizeof(addr));
}

DatagramSocket::~DatagramSocket()
{
#if WIN32
    closesocket(sock);
    WSACleanup();
#else
    close(sock);
#endif
}

int DatagramSocket::getAddress(const char * name, char * addr)
{
    struct hostent *hp;
    if ((hp = gethostbyname(name)) == nullptr) return (0);
    strcpy(addr, inet_ntoa( *reinterpret_cast<struct in_addr *>(hp->h_addr)));
    return (1);
}

const char* DatagramSocket::getAddress(const char * name)
{
    struct hostent *hp;
    if ((hp = gethostbyname(name)) == nullptr)
        return (nullptr);
    strcpy(ip, inet_ntoa( *reinterpret_cast<struct in_addr *>(hp->h_addr)));
    return ip;
}

long DatagramSocket::receive(char* msg, int msgsize)
{
    struct sockaddr_in sender;
    socklen_t sendersize = sizeof(sender);
    int retval = recvfrom(sock,msg,msgsize,0, reinterpret_cast<struct sockaddr *>(&sender), &sendersize);
    strncpy(received,inet_ntoa(sender.sin_addr), 2047);
    return retval;
}

char* DatagramSocket::received_from()
{
    return received;
}

long DatagramSocket::send(const char* msg, int msgsize)
{
    return sendto(sock, msg, msgsize, 0, reinterpret_cast<struct sockaddr *>(&outaddr),sizeof(outaddr));
}

long DatagramSocket::sendTo(const char* msg, int msgsize, const char* addr)
{
    outaddr.sin_addr.s_addr = inet_addr(addr);
    return sendto(sock, msg, msgsize, 0, reinterpret_cast<struct sockaddr *>(&outaddr),sizeof(outaddr));
}
