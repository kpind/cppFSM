#include "fsm.h"


FiniteStateMachine::FiniteStateMachine(FsmState* initialState) {
    currentState = initialState;
}


FsmState* FiniteStateMachine::getCurrentState(void){
    return currentState;
}


void FiniteStateMachine::sendEvent(FsmEvent ev) {
    currentState = currentState->handleEvent(ev);
}

