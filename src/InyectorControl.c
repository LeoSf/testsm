/**
 *  \file InyectorControl.c
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
#include "InyectorControlAct.h"

/* ----------------------------- Local macros ------------------------------ */
/* ------------------------------- Constants ------------------------------- */
/* ---------------------------- Local data types --------------------------- */
/* ---------------------------- Global variables --------------------------- */
/* ---------------------------- Local variables ---------------------------- */
static int state;

/* ----------------------- Local function prototypes ----------------------- */
/* ---------------------------- Global functions --------------------------- */
int 
InyectorControl_init(void)
{
    state = off; 
    InyectorControlAct_init();
    return state;
}

/* ------------------------------ File footer ------------------------------ */
