#include "fsm.h"


FsmTransition::FsmTransition(FsmEvent& ev, FsmState* dst)
{
    event = ev;
    destination = dst;
}

FsmEvent& FsmTransition::getEvent(void) {
    return event;
}

