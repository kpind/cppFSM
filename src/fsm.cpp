#include "fsm.h"


FiniteStateMachine::FiniteStateMachine(FsmState* initialState) {
    currentState = initialState;
}


FsmState* FiniteStateMachine::getCurrentState(void){
    return currentState;
}


void FiniteStateMachine::sendEvent(FsmEvent ev) {
    FsmState* newState = currentState->handleEvent(ev);
    if (newState != currentState) {
        currentState->exit();
    }
    currentState = newState;
}

