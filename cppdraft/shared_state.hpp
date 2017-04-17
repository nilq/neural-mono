#ifndef shared_state_h
#define shared_state_h

#include <stdint.h>

struct SharedState {
    SharedState();
    void reset();

    uint16_t agentX;

    bool operator == (SharedState const & rhs) const;
    bool operator != (SharedState const & rhs) const;    
};

#endif