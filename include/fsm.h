#ifndef __FSM_H_
#define __FSM_H_


#include <queue>
#include <string>
#include <vector>



class FsmState;


class FsmEvent {
    public:
        FsmEvent() {};
        FsmEvent(int id, std::string);
        int getId(void) { return eventId; }
        std::string getName(void) { return eventName; }
        void setName(std::string name) { eventName.assign(name); }

    private:
        std::string eventName;
        int eventId;
};



class FsmTransition {
    public:
        FsmTransition() {};
        FsmTransition(FsmEvent&, FsmState*);
        FsmState* getDestinationState(void) { return destination; }
        FsmEvent& getEvent(void);

    private:
        int transitionId;
        FsmEvent event;
        FsmState* destination;
};



class FsmState {
    public:
        FsmState();
        FsmState(std::string);
        void entry(void) {};
        void exit(void) {};
        FsmState* handleEvent(FsmEvent);
        std::string getName();
        void addTransition(FsmTransition&);

    private:
        std::string stateName;
        std::vector<FsmTransition> transitions = std::vector<FsmTransition>();
};


class FiniteStateMachine {
    public:
        FiniteStateMachine();
        FiniteStateMachine(FsmState* initialState);
        FsmState* getCurrentState(void);
        void sendEvent(FsmEvent);
    private:
        std::queue<FsmEvent> eventQueue;
        FsmState* currentState;
};

#endif
