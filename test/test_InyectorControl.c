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
#include "unity_fixture.h"
#include "InyectorControl.h"
#include "Mock_InyectorControlAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
TEST_GROUP(Structure);

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
TEST_SETUP(Structure)
{
    Mock_InyectorControlAct_Init();
}

TEST_TEAR_DOWN(Structure)
{
    Mock_InyectorControlAct_Verify();
    Mock_InyectorControlAct_Destroy();
}

TEST(Structure, DefaultStateAfterInit)
{
    InyectorControlAct_init_Expect();
    expectNextState = InyectorControl_init();
    TEST_ASSERT_EQUAL(off, expectNextState);
}

TEST(Structure, AnUnhandledEventDoesNotChangeState)
{
    setProfile(off, UNHANDLED_EVENT, evStartTimeout);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
    TEST_ASSERT_EQUAL(off, InyectorControl_getState());
}

TEST(Structure, StateTransitionTableForOff)
{
    setProfile(off, starting, evStart);
    InyectorControlAct_starting_Expect(&event);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
}

TEST(Structure, StateTransitionTableForStarting)
{
    setProfile(starting, idleSpeed, evStartTimeout);
    state = InyectorControl_dispatch(&event);
    TEST_ASSERT_EQUAL(expectNextState, state);
}

/* ------------------------------ File footer ------------------------------ */
