/**
 *  \file test_InyectorControl.c
 */

/* -------------------------- Development history -------------------------- */
/*
 *  2017.06.21  LeFr  v1.0.00  Initial version
 */

/* -------------------------------- Authors -------------------------------- */
/*
 *  LeFr  Leandro Francucci  francuccilea@gmail.com
 */

/* --------------------------------- Notes --------------------------------- */
/* ----------------------------- Include files ----------------------------- */
#include "unity.h"
#include "InyectorControlAct.h"
#include "Mock_Timer.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static Event event;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
/* ---------------------------- Global functions --------------------------- */
void
setUp(void)
{
    Mock_Timer_Init();
}

void
tearDown(void)
{
    Mock_Timer_Verify();
    Mock_Timer_Destroy();
}

void
test_SetInitialValuesAfterInit(void)
{
    Timer *tmr = (Timer *)0xdeadbeef;

    Timer_init_ExpectAndReturn(START_TIME, 0, evStartTimeout, tmr);

    InyectorControlAct_init();
}

void
test_SetDutyTo50ForAWhileOnStart(void)
{
    Timer *tmr = (Timer *)0xdeadbeef;
    event.signal = evStart;

    Timer_start_Expect(tmr);
    Timer_start_IgnoreArg_me();

    InyectorControlAct_starting(&event);
}

/* ------------------------------ File footer ------------------------------ */
