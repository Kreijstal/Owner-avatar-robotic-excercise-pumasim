// *******************************************************************
// UiAgent.h
//
// This file declares the UiAgent class, and the global ui pointer.
// The servo uses the UiAgent class to send messages to the UI.  Note
// that the servo typically has two UIs: the remote GUI, and the local
// text/gather UI.
// *******************************************************************
#ifndef UI_AGENT_H
#define UI_AGENT_H

#include "XPrintf.h"
#include "unitMsg.h"
#include "cs225.h"
#include "PrVector6.h"
#include "MesgQueue.h"
#include "PrDataInput.h"
#include "PrDataOutput.h"
#include "PrSocket.h"

/**
* \ingroup sim
* \brief Class that defines the servo's interface to the UI.
*
* The implementation used in the simulation system makes use of the
* MesgQueue class to communicate with the UI.  The real-time
* implementation makes use of sockets instead.
*/

class UiAgent
{
public:
  UiAgent();                         // Constructor for local UI
  UiAgent( PrSocket* remoteSocket ); // Constructor for remote UI
  ~UiAgent();

  bool IsDataAvailable( void );

  // Sends a message.
  void Send( CMsg& msg, DestinationUi dest=GUI );

  // Reads a message, assuming data was available.
  CMappedMsg GetMsg();

  // Send a GATHER_DATA message
  void DoGather( Float curTime, PrVector* gatherData[] );

  /**
  * \brief Sends a given string to the TextUI for display.
  *
  * This function takes the place of printf(), since you are not
  * allowed to call printf() when running in kernel (real-time) mode.
  * printf() is redefined to call this function (via XPrintf)
  * whenever ui is non-NULL.
  */
  int Display( const char * fmt, ... );
  //int VDisplay( const char * fmt, va_list argptr );

private:
  enum InputSource { IS_NONE, IS_LOCAL, IS_REMOTE };

  MesgQueue*    m_servoToUiLoc;  // Output to local UI
  MesgQueue*    m_uiToServoLoc;  // Input from local UI
  PrDataOutput* m_servoToUiRem;  // Output to remote UI (may be NULL)
  PrDataInput*  m_uiToServoRem;  // Input from remote UI (may be NULL)
  InputSource   m_inputSource;   // Set by IsDataAvailable(), used by Send()

  char m_printBuffer[MAX_MSG_SIZE - 32];    // Used by Display()
  int  m_printSize;
};

extern UiAgent * ui;

#endif // UI_AGENT_H
