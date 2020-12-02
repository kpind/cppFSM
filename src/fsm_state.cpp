#include "fsm.h"


FsmState::FsmState() : stateName() {
}


FsmState::FsmState(std::string name) : stateName(name) {
}


void FsmState::addTransition(FsmTransition& tr) {
    transitions.push_back(tr);
}


std::string FsmState::getName() {
    return stateName;
}


FsmState* FsmState::handleEvent(FsmEvent ev) {
    FsmState* newState = this;

    std::vector<FsmTransition>::iterator itr;
    for (itr = transitions.begin(); itr != transitions.end(); ++itr) {
        if ((*itr).getEvent().getId() == ev.getId()) {
            newState = (*itr).getDestinationState();
            break;
        }
    }
    return newState;
}

