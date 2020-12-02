#include <iostream>
#include <array>

#include "fsm.h"


#define EV_INIT     1
#define EV_UNLOCK   2
#define EV_LOCK     3
#define EV_OPEN     4
#define EV_CLOSE    5
#define EV_TERM     6


int main() {

    FsmState initState("Initial");
    FsmState lockedState("Locked");
    FsmState unlockedState("Unlocked");
    FsmState openState("Open");
    FsmState finalState("Final");

    FsmEvent ev_init(EV_INIT, "init");
    FsmEvent ev_unlock(EV_UNLOCK, "unlock");
    FsmEvent ev_lock(EV_LOCK, "lock");
    FsmEvent ev_open(EV_OPEN, "open");
    FsmEvent ev_close(EV_CLOSE, "close");
    FsmEvent ev_terminate(EV_TERM, "terminate");

    FsmTransition tr_init(ev_init, &lockedState);
    FsmTransition tr_unlock(ev_unlock, &unlockedState);
    FsmTransition tr_lock(ev_lock, &lockedState);
    FsmTransition tr_open(ev_open, &openState);
    FsmTransition tr_close(ev_close, &unlockedState);
    FsmTransition tr_term(ev_terminate, &finalState);

    initState.addTransition(tr_init);

    lockedState.addTransition(tr_unlock);
    lockedState.addTransition(tr_term);

    unlockedState.addTransition(tr_lock);
    unlockedState.addTransition(tr_open);
    unlockedState.addTransition(tr_term);

    openState.addTransition(tr_close);
    openState.addTransition(tr_term);

    FiniteStateMachine fsm(&initState);

    std::array<FsmEvent, 7> events { ev_init, ev_unlock, ev_open, ev_lock, ev_unlock, ev_init, ev_terminate};

    for (FsmEvent ev : events) {
        std::cout << ev.getName() << ": " << fsm.getCurrentState()->getName() << " --> ";
        fsm.sendEvent(ev);
        std::cout << fsm.getCurrentState()->getName() << std::endl;
    }

    return 0;
}
