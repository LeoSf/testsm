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
#include "RPMControl.h"
#include "TempSensor.h"
#include "RPMSensor.h"
#include "ThrottleSensor.h"
#include "PWMInyector.h"
#include "Sensor.h"
#include "Timer.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static int tempVal, rpmVal, throttleVal;
static TempSensor *temp;
static RPMSensor *rpm;
static ThrottleSensor *throttle;
static unsigned char duty;
static Timer *startTmr;

/* ----------------------- Local function prototypes ----------------------- */
static int
calcDutyFromThrottle(int currThrottleVal)
{
    return currThrottleVal;
}

/* ---------------------------- Global functions --------------------------- */
/* Init action */
void 
InyectorControlAct_init(void)
{
    tempVal = rpmVal = throttleVal = 0;
    duty = 0;

    temp = TempSensor_init();
    rpm = RPMSensor_init();
    throttle = ThrottleSensor_init();
    RPMControl_init(IDLE_MIN_DUTY, IDLE_MAX_DUTY, IDLE_RPM, IDLE_RPM_THH, 
                    IDLE_RPM_THL);
    PWMInyector_init();
    startTmr = Timer_init(START_TIME, 0, evStartTimeout);
}

/* Effect actions */
void 
InyectorControlAct_onIdleSpeed(Event *event)
{
    tempVal = Sensor_get((Sensor *)temp);
    rpmVal = Sensor_get((Sensor *)rpm);

    duty = RPMControl_compute(rpmVal);
    PWMInyector_setDuty(duty);
}

void 
InyectorControlAct_onNormal(Event *event)
{
    tempVal = Sensor_get((Sensor *)temp);
    rpmVal = Sensor_get((Sensor *)rpm);

    duty = calcDutyFromThrottle(throttleVal);

    if (tempVal < ENGINE_MIN_TEMP)
    {
        duty += INC_DUTY_FOR_COLD;
    }

    PWMInyector_setDuty(duty);
}


/* Guard actions */
bool 
InyectorControlAct_isPressedThrottle(Event *event)
{
    throttleVal = Sensor_get((Sensor *)throttle);
    return throttleVal > THROTTLE_MIN;
}

bool 
InyectorControlAct_isReleasedThrottle(Event *event)
{
    throttleVal  = Sensor_get((Sensor *)throttle);
    return throttleVal <= THROTTLE_MIN;
}


/* Entry actions */
void 
InyectorControlAct_starting(Event *event)
{
    Timer_start(startTmr);
    PWMInyector_setDuty(START_DUTY);
}


/* Exit actions */
/* ------------------------------ File footer ------------------------------ */
