#ifndef CONTROL_DLL_H
#define CONTROL_DLL_H
  
#include "GlobalVariables.h"

#ifdef _WIN32

void InitControl(GlobalVariables& gv);
void jmoveControl(GlobalVariables& gv);
void ngotoControl(GlobalVariables& gv);
void gotoControl(GlobalVariables& gv);



#elif __linux__

void InitControl(GlobalVariables& gv) ;
void PreprocessControl(GlobalVariables& gv) ;
void PostprocessControl(GlobalVariables& gv) ;

// Initialization functions for each control law.
// Called once when a new control mode is set.

void initFloatControl(GlobalVariables& gv) ;
void initNjholdControl(GlobalVariables& gv) ;
void initJholdControl(GlobalVariables& gv) ;
void initOpenControl(GlobalVariables& gv) ;
void initNjmoveControl(GlobalVariables& gv) ;
void initJmoveControl(GlobalVariables& gv) ;
void initNjgotoControl(GlobalVariables& gv) ;
void initJgotoControl(GlobalVariables& gv) ;
void initNjtrackControl(GlobalVariables& gv) ;
void initJtrackControl(GlobalVariables& gv) ;
void initNxtrackControl(GlobalVariables& gv) ;
void initXtrackControl(GlobalVariables& gv) ;
void initNholdControl(GlobalVariables& gv) ;
void initHoldControl(GlobalVariables& gv) ;
void initNgotoControl(GlobalVariables& gv) ;
void initGotoControl(GlobalVariables& gv) ;
void initNtrackControl(GlobalVariables& gv) ;
void initTrackControl(GlobalVariables& gv) ;
void initPfmoveControl(GlobalVariables& gv) ;
void initLineControl(GlobalVariables& gv) ;
void initProj1Control(GlobalVariables& gv) ;
void initProj2Control(GlobalVariables& gv) ;
void initProj3Control(GlobalVariables& gv) ;

// Functions containing the actual control laws.

void noControl(GlobalVariables& gv) ;
void floatControl(GlobalVariables& gv) ;
void njholdControl(GlobalVariables& gv) ;
void jholdControl(GlobalVariables& gv) ;
void openControl(GlobalVariables& gv) ;
void njmoveControl(GlobalVariables& gv) ;
void jmoveControl(GlobalVariables& gv) ;
void njgotoControl(GlobalVariables& gv) ;
void jgotoControl(GlobalVariables& gv) ;
void njtrackControl(GlobalVariables& gv) ;
void jtrackControl(GlobalVariables& gv) ;
void nxtrackControl(GlobalVariables& gv) ;
void xtrackControl(GlobalVariables& gv) ;
void nholdControl(GlobalVariables& gv) ;
void holdControl(GlobalVariables& gv) ;
void ngotoControl(GlobalVariables& gv) ;
void gotoControl(GlobalVariables& gv) ;
void ntrackControl(GlobalVariables& gv) ;
void trackControl(GlobalVariables& gv) ;
void pfmoveControl(GlobalVariables& gv) ;
void lineControl(GlobalVariables& gv) ;
void proj1Control(GlobalVariables& gv) ;
void proj2Control(GlobalVariables& gv) ;
void proj3Control(GlobalVariables& gv) ;

// PrintDebug is called when you type pdebug at the prompt
void PrintDebug(GlobalVariables& gv) ;

// Initialize your variables here.  InitControl() is called just once,
// before the first servo loop.  PreprocessControl() is called on
// every servo loop just before the control law function, and
// PostprocessControl() is called just after the control law function.
extern "C"
{
void _InitControl(GlobalVariables& gv){InitControl(gv);}
void _PreprocessControl(GlobalVariables& gv){PreprocessControl(gv);}
void _PostprocessControl(GlobalVariables& gv){PostprocessControl(gv);}

// Initialization functions for each control law.
// Called once when a new control mode is set.

void _initFloatControl(GlobalVariables& gv){initFloatControl(gv);}
void _initNjholdControl(GlobalVariables& gv){initNjholdControl(gv);}
void _initJholdControl(GlobalVariables& gv){initJholdControl(gv);}
void _initOpenControl(GlobalVariables& gv){initOpenControl(gv);}
void _initNjmoveControl(GlobalVariables& gv){initNjmoveControl(gv);}
void _initJmoveControl(GlobalVariables& gv){initJmoveControl(gv);}
void _initNjgotoControl(GlobalVariables& gv){initNjgotoControl(gv);}
void _initJgotoControl(GlobalVariables& gv){initJgotoControl(gv);}
void _initNjtrackControl(GlobalVariables& gv){initNjtrackControl(gv);}
void _initJtrackControl(GlobalVariables& gv){initJtrackControl(gv);}
void _initNxtrackControl(GlobalVariables& gv){initNxtrackControl(gv);}
void _initXtrackControl(GlobalVariables& gv){initXtrackControl(gv);}
void _initNholdControl(GlobalVariables& gv){initNholdControl(gv);}
void _initHoldControl(GlobalVariables& gv){initHoldControl(gv);}
void _initNgotoControl(GlobalVariables& gv){initNgotoControl(gv);}
void _initGotoControl(GlobalVariables& gv){initGotoControl(gv);}
void _initNtrackControl(GlobalVariables& gv){initNtrackControl(gv);}
void _initTrackControl(GlobalVariables& gv){initTrackControl(gv);}
void _initPfmoveControl(GlobalVariables& gv){initPfmoveControl(gv);}
void _initLineControl(GlobalVariables& gv){initLineControl(gv);}
void _initProj1Control(GlobalVariables& gv){initProj1Control(gv);}
void _initProj2Control(GlobalVariables& gv){initProj2Control(gv);}
void _initProj3Control(GlobalVariables& gv){initProj3Control(gv);}

// Functions containing the actual control laws.

void _noControl(GlobalVariables& gv){noControl(gv);}
void _floatControl(GlobalVariables& gv){floatControl(gv);}
void _njholdControl(GlobalVariables& gv){njholdControl(gv);}
void _jholdControl(GlobalVariables& gv){jholdControl(gv);}
void _openControl(GlobalVariables& gv){openControl(gv);}
void _njmoveControl(GlobalVariables& gv){njmoveControl(gv);}
void _jmoveControl(GlobalVariables& gv){jmoveControl(gv);}
void _njgotoControl(GlobalVariables& gv){njgotoControl(gv);}
void _jgotoControl(GlobalVariables& gv){jgotoControl(gv);}
void _njtrackControl(GlobalVariables& gv){njtrackControl(gv);}
void _jtrackControl(GlobalVariables& gv){jtrackControl(gv);}
void _nxtrackControl(GlobalVariables& gv){nxtrackControl(gv);}
void _xtrackControl(GlobalVariables& gv){xtrackControl(gv);}
void _nholdControl(GlobalVariables& gv){nholdControl(gv);}
void _holdControl(GlobalVariables& gv){holdControl(gv);}
void _ngotoControl(GlobalVariables& gv){ngotoControl(gv);}
void _gotoControl(GlobalVariables& gv){gotoControl(gv);}
void _ntrackControl(GlobalVariables& gv){ntrackControl(gv);}
void _trackControl(GlobalVariables& gv){trackControl(gv);}
void _pfmoveControl(GlobalVariables& gv){pfmoveControl(gv);}
void _lineControl(GlobalVariables& gv){lineControl(gv);}
void _proj1Control(GlobalVariables& gv){proj1Control(gv);}
void _proj2Control(GlobalVariables& gv){proj2Control(gv);}
void _proj3Control(GlobalVariables& gv){proj3Control(gv);}

// PrintDebug is called when you type pdebug at the prompt
void _PrintDebug(GlobalVariables& gv){PrintDebug(gv);}
}

#endif


#endif
