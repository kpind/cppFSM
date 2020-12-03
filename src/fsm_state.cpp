#include "fsm.h"


FsmState::FsmState() : stateName() {
    exitAction = nullptr;
    entryAction = nullptr;
}


FsmState::FsmState(std::string name) : stateName(name) {
    exitAction = nullptr;
    entryAction = nullptr;
}


void FsmState::addTransition(FsmTransition& tr) {
    transitions.push_back(tr);
}


void FsmState::setEntryAction(void(*action)(void)) {
    entryAction = action;
}


void FsmState::setExitAction(void(*action)(void)) {
    exitAction = action;
}


void FsmState::entry(void) {
    if (nullptr != entryAction) {
        entryAction();
    }
}


void FsmState::exit(void) {
    if (nullptr != exitAction) {
        exitAction();
    }
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

