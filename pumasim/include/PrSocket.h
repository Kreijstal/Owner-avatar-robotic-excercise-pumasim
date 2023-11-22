/***************************************************************
* PrSocket.h
*
* This class provides Socket methods.
*
****************************************************************/

/*
* modification history
*----------------------
*
* 02/12/98: K.C. Chang: created.
*/

#ifndef _PrSocket_h
#define _PrSocket_h

#include "PrGlobalDefn.h"

#define PR_SOCKET_OK    1
#define PR_SOCKET_ERROR 0

class PrSocket
{
public:
   PrSocket( int sockfd );
   PrSocket( char *hostname, int portNum );

   ~PrSocket();

   int flag() { return flag_; }

   int socketFD() { return socketFD_; }

   void close();

private:
   int flag_;
   int socketFD_;

   int Init();
   int Connect( char *hostname, int portNum );

   // copy is not allowed
   PrSocket( const PrSocket & ) {}
};

#endif // _PrSocket_h