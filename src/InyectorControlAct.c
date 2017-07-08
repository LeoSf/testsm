/** 
 * \file InyectorControlAct.c 
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
/* ----------------------------- Include files ----------------------------- */
#include "InyectorControl.h"
#include "PWMInyector.h"
#include "Timer.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static unsigned char duty;
static Timer *startTmr;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Global functions --------------------------- */
/* Init action */
void 
InyectorControlAct_init(void)
{
    duty = 0;

    PWMInyector_init();
    startTmr = Timer_init(START_TIME, 0, evStartTimeout);
}

/* Effect actions */
/* Guard actions */
/* Entry actions */
void 
InyectorControlAct_starting(Event *event)
{
    Timer_start(startTmr);
    PWMInyector_setDuty(START_DUTY);
}

void 
InyectorControlAct_entryIdleSpeed(Event *event)
{
    PWMInyector_setDuty(IDLE_MIN_DUTY);
}

/* Exit actions */
/* ------------------------------ File footer ------------------------------ */
