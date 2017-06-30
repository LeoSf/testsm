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
#include "InyectorControl.h"
#include "Mock_InyectorControlAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static int state, expectNextState;
static Event event;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Local functions ---------------------------- */
static void
setProfile(int currState, int nextState, int signal)
{
    InyectorControl_setState(currState);
    event.signal = signal;
    expectNextState = nextState;
}

/* ---------------------------- Global functions --------------------------- */
void
setUp(void)
{
    Mock_InyectorControlAct_Init();
}

void
tearDown(void)
{
    Mock_InyectorControlAct_Verify();
    Mock_InyectorControlAct_Destroy();
}

void
test_DefaultStateAfterInit(void)
{
    InyectorControlAct_init_Expect();
    expectNextState = InyectorControl_init();
    TEST_ASSERT_EQUAL(off, expectNextState);
}

void
test_AnUnhandledEventDoesNotChangeState(void)
{
    setProfile(off, UNHANDLED_EVENT, evStartTimeout);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
    TEST_ASSERT_EQUAL(off, InyectorControl_getState());
}

void
test_StateTransitionTableForOff(void)
{
    setProfile(off, starting, evStart);
    InyectorControlAct_starting_Expect(&event);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
}

void
test_StateTransitionTableForStarting(void)
{
    setProfile(starting, idleSpeed, evStartTimeout);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
}

/* ------------------------------ File footer ------------------------------ */
