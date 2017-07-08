/** 
 * \file Timer.h 
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
#ifndef __TIMER_H__
#define __TIMER_H__

/* ----------------------------- Include files ----------------------------- */
/* ---------------------- External C language linkage ---------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------- Macros -------------------------------- */
/* -------------------------------- Constants ------------------------------ */
/* ------------------------------- Data types ------------------------------ */
typedef struct Timer Timer;

/* -------------------------- External variables --------------------------- */
/* -------------------------- Function prototypes -------------------------- */
Timer *Timer_init(int count, int period, int eventSignal);
void Timer_start(Timer *const me);
 
/* -------------------- External C language linkage end -------------------- */
#ifdef __cplusplus
}
#endif

/* ------------------------------ Module end ------------------------------- */
#endif
