/***************************************************************
* PrDataInput.h
*
* This class provides Data Input methods.
*
****************************************************************/

/*
* modification history
*----------------------
*
* 02/14/98: K.C. Chang: created.
*/

#ifndef _PrDataInput_h
#define _PrDataInput_h

#include "PrGlobalDefn.h"
#include "PrNetworkDefn.h"
#include "unitMsg.h"

#define PR_DATAINPUT_OK    1
#define PR_DATAINPUT_ERROR -2

class PrSocket;

class PrDataInput
{
public:
  PrDataInput( PrSocket *socket, int bufferSize = PR_NETWORK_BUFFER_SIZE );
  ~PrDataInput();

  bool IsDataAvailable() { return ready() > 0; }

  // number of data bytes
  int ready();

  CMappedMsg GetMsg();


  int select( long msec );

  // number of data bytes
  void bufferSize( int nbytes );


private:
  int socketFD_;
  char *buffer_;
  int bufferSize_;
  int byteCounter_;
  short size_;
  int readSize_;  // number of tcp ip messeges read

  void Init( int nbytes );
  int InitByteCounter();

  int Peek( char *buff, int nbytes );
  int Peek();

  int Receive();

  short  Unpack2B( char *text );
  // copy is not allowed
  PrDataInput( const PrDataInput & ) {}
};


inline int PrDataInput::InitByteCounter()
{
  byteCounter_ = 4; // 2*sizeof(short);
  return byteCounter_;
}


#endif // _PrDataInput_h



