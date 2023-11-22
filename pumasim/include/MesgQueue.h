#ifndef MESGQUEUE_H
#define MESGQUEUE_H

#include "unitMsg.h"
#include <pthread.h>

static const int QUEUE_SIZE = 500000;
static const int COLS_NUM = 2;

// Communication mechanism between servo and UI in a simulation environment.
// I believe this implementation is thread-safe...(for one reader and one writer).
// IrenaP: only if the access is from a single thread.

/**
* \ingroup utility
* \brief Communication mechanism between servo and UI in a simulation environment.
*
* Replaces the functionality of the RTLinux FIFO mechanism that is used for
* communication between the real-time servo and the user space UI in the
* real-time environment.  I believe this implementation is safe for one reader
* and one writer.  If traffic flow is very high, you may have to increase the
* QUEUE_SIZE constant.
*
* Note that this is a singleton, to facilitate sharing between the servo and
* the UI.
*/

class MesgQueue {
public:
  /**
  * \brief Returns a MesgQueue object corresponding to the given \a id,
  * constructing it if necessary.
  *
  * This is the only way to get hold of an object of this class.  There is no
  * public constructor.  Multiple clients may get hold of the same object by
  * specifying the same \a id.
  */

  static MesgQueue * GetQueue( int id );
  static void Fini();

  /**
  * \brief Returns the unique identifier for this MesgQueue object.
  */

  int id() { return _id; }

  /**
  * \brief Checks if the queue currently contains data.
  *
  * \return \c true if there is data, \c false otherwise.
  */

  bool IsDataAvailable( void );

  //@{
  /**
  * \brief Puts the message onto the queue
  */
  void Send( CMsg& msg );

  /**
  * \brief Assuming data is available, maps the message
  *        into a message structure.
  *
  * \return \c CMappedMsg structure.
  */
  CMappedMsg GetMsg();


private:
  static MesgQueue* s_queueCollection[COLS_NUM];
  static int        s_cCols;
  MesgQueue( int id );    // Only allow instantiation through GetQueue().
  ~MesgQueue();
  void WriteBytes( const char * data, int size );
  void ReadBytes( char * data, int size );


  int _id;
  char* buffer;
  int readIndex;
  int writeIndex;

  pthread_mutex_t sharedMutex;
};

#endif
