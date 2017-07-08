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
#include "Timer.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static Timer *startTmr;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Global functions --------------------------- */
/* Init action */
void 
InyectorControlAct_init(void)
{
    startTmr = Timer_init(START_TIME, 0, evStartTimeout);
}

/* Effect actions */
/* Guard actions */
/* Entry actions */
void 
InyectorControlAct_starting(Event *event)
{
    Timer_start(startTmr);
}

/* Exit actions */
/* ------------------------------ File footer ------------------------------ */
