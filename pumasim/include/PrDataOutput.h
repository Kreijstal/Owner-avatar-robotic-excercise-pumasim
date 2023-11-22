/***************************************************************
* PrDataOutput.h
*
* This class provides Data Output methods.
*
****************************************************************/

/*
* modification history
*----------------------
*
* 02/14/98: K.C. Chang: created.
*/

#ifndef _PrDataOutput_h
#define _PrDataOutput_h

#include "unitMsg.h"
#include "PrGlobalDefn.h"
#include "PrNetworkDefn.h"

#define PR_DATAOUTPUT_OK    1
#define PR_DATAOUTPUT_ERROR 0

class PrSocket;

class PrDataOutput
{
public:
  PrDataOutput( PrSocket *socket, int bufferSize = PR_NETWORK_BUFFER_SIZE );
  ~PrDataOutput();

  int Send( CMsg& msg );

  void bufferSize( int nbytes );

private:
  int socketFD_;
  char *buffer_;
  int bufferSize_;
  int byteCounter_;

  void Init(int nbytes);
  int InitByteCounter();

  int Send( const char* buffer ) const;

  // copy is not allowed
  PrDataOutput( const PrDataOutput & ) {}
};

inline int PrDataOutput::InitByteCounter()
{
  byteCounter_ = 4; // 2*sizeof(short);
  return byteCounter_;
}

#endif // _PrDataOutput_h



