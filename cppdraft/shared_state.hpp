#ifndef shared_state_h
#define shared_state_h

#include <stdint.h>

struct SharedState {
    SharedState();
    void reset();

    bool operator == (SharedState const & rhs) const;
    bool operator != (SharedState const & rhs) const;    
};

#endif