// *******************************************************************
// param.h
//
// This file provides constants for a simplified model of the PUMA,
// which can be used to generate a mass matrix, B matrix, gravity
// vector, and so on.
// *******************************************************************
#ifndef PARAM_H
#define PARAM_H

#include "PrGlobalDefn.h"

// Force of gravity

static const Float GRAVITY = -9.81f;

// Link lengths.  Use L6, not L6a, for the last link, as described in
// the "Last Link" section.

static const Float L1  = 0.2435f - 0.0934f;  // Distance from base to arm
static const Float L2  = 0.4318f - 0.0203f;  // Length of upper arm
static const Float L3  = 0.4331f;           // Length of lower arm
static const Float L6a = 0.055f; // Distance from wrist to tip of end-effector


// Center of Mass measurements.  Use R6, not R6a, for the last link,
// as described in the "Last Link" section.

static const Float R1  = 0;       // Distance from base to COM of shoulder
static const Float R2  = 0.0680f;  // Distance from frame 1 to COM of upper arm
static const Float R3  = 0.1430f;  // Distance from frame 2 to COM of lower arm
static const Float R6a = 0.032f;   // Distance from frame 6 to COM of effector


// Mass of each link. Use M6, not M6a, for the last link, as described
// in the "Last Link" section.

static const Float M1  = 34.40f;
static const Float M2  = 17.40f;
static const Float M3  =  6.04f;
static const Float M4  =  0.82f;
static const Float M5  =  0.34f;
static const Float M6a =  0.09f;

// Moments of inertia, including motor inertia, plus some fudge
// factors to compensate for some approximations in our model.
// (U

static const Float Izz1  = 0.3500f  + 1.1400f + 1.2f;
static const Float Izz2  = 0.5390f  + 4.7100f;
static const Float Izz3  = 0.2120f  + 0.8300f;
static const Float Izz4  = 0.0013f  + 0.2000f;
static const Float Izz5  = 0.0004f  + 0.1790f + 0.02f;
static const Float Izz6a = 0.00004f + 0.1930f;


// Length, mass, center of mass, & inertia for the force sensor and
// gripper.  Don't use these values directly.

static const Float L6b   = 0.035f;
static const Float M6b   = 0.20f;
static const Float R6b   = 0.015f;
static const Float Izz6b = 0.02f;

static const Float L6c   = 0.105f;
static const Float M6c   = 0.20f;
static const Float R6c   = 0.050f;
static const Float Izz6c = 0.02f;

// Last Link
//
// The last link may have a force sensor and/or gripper attached,
// which changes its length, mass, and so on.  Uncomment one of these
// four sections to get the effective values of L6, R6, M6, and Izz6.

// (1) No force sensor or gripper
    static const Float L6   = L6a;
    static const Float M6   = M6a;
    static const Float R6   = R6a;
    static const Float Izz6 = Izz6a;

// (2) Force sensor only
//    static const Float L6   = L6a + L6b;
//    static const Float M6   = M6a + M6b;
//    static const Float R6   = (M6a*R6a + M6b*(L6a+R6b)) / M6;
//    static const Float Izz6 = Izz6a + Izz6b +
//                              M6a * (R6a-R6) * (R6a-R6) +
//                              M6b * (L6a+R6b-R6) * (L6a+R6b-R6);

// (3) Gripper only
// static const Float L6   = L6a + L6c;
// static const Float M6   = M6a + M6c;
// static const Float R6   = (M6a*R6a + M6c*(L6a+R6c)) / M6;
// static const Float Izz6 = Izz6a + Izz6c + M6a * (R6a-R6) * (R6a-R6) + M6c * (L6a+R6c-R6) * (L6a+R6c-R6);

// (4) Force sensor and gripper
/*static const Float L6 = L6a + L6b + L6c;
static const Float M6 = M6a + M6b + M6c;
static const Float R6 = (M6a*R6a + M6b*(L6a+R6b) + M6c*(L6a+L6b+R6c))/M6;
static const Float Izz6 = Izz6a + Izz6b + Izz6c +
M6a * (R6a-R6) * (R6a-R6) +
M6b * (L6a+R6b-R6) * (L6a+R6b-R6) +
M6c * (L6a+L6b+R6c-R6) * (L6a+L6b+R6c-R6);
*/

#endif // PARAM_H
