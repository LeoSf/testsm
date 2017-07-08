/** 
 * \file InyectorControl.h 
 */

/* -------------------------- Development history -------------------------- */
/*
 *  2017.06.20  LeFr  v2.4.05  Initial version
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci  francuccilea@gmail.com
 */

/* --------------------------------- Notes --------------------------------- */
/* --------------------------------- Module -------------------------------- */
#ifndef __INYECTORCONTROL_H__
#define __INYECTORCONTROL_H__
 
/* ----------------------------- Include files ----------------------------- */
/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
#define START_TIME          2000    /* In milliseconds */
#define START_DUTY          50      /* In percentage */
#define IDLE_MIN_DUTY       20      /* In percentage */
#define IDLE_MAX_DUTY       30      /* In percentage */
#define THROTTLE_MIN        30      /* Throttle pedal position */
#define THROTTLE_MAX        80      /* Throttle pedal position */
#define IDLE_RPM            2000    /* In RPM */
#define IDLE_RPM_THH        20      /* In RPM */
#define IDLE_RPM_THL        20      /* In RPM */
#define INC_DUTY_FOR_COLD   10      /* In percentage */
#define TICK_TIME           100     /* In milliseconds */
#define ENGINE_MIN_TEMP     70      /* In Celcius */

#define UNHANDLED_EVENT     (-1)

/* States */
enum
{
    off, starting, idleSpeed
};
 
/* Event signals */
enum
{
    evStart, evStartTimeout
};
 
/* ------------------------------- Data types ------------------------------ */
typedef struct Event Event;
struct Event
{
    int signal;
};
 
/* -------------------------- External variables --------------------------- */
/* -------------------------- Function prototypes -------------------------- */
int InyectorControl_init(void);
int InyectorControl_dispatch(Event *event);
void InyectorControl_setState(int currState);
int InyectorControl_getState(void);
 
/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif
