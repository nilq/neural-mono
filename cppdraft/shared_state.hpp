#ifndef shared_state_h
#define shared_state_h

#include <stdint.h>

struct SharedState {
    enum Simulation {
        Running,
    } simulation;

    Simulation nextState;

    uint32_t msNow;
    uint16_t agentX;
    
    SharedState();
    void reset();
    bool operator == (SharedState const & rhs) const;
    bool operator != (SharedState const & rhs) const;    
};

#endif