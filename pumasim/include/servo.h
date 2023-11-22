#ifndef SERVO_H
#define SERVO_H

#include <vector>
#include "cs225.h"
#include "UiAgent.h"
#include "PrVector3.h"
#include "PrVector6.h"
#include "PrMatrix3.h"
#include "PrMatrix6.h"
#include "Utils.h"
#include "PrTransform.h"

#include "GlobalVariables.h"

extern GlobalVariables gv;

// The servo loop

void* servoLoop( void * );



#endif
