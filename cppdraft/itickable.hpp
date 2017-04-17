#ifndef itickable_h
#define itickable_h

#include "shared_state.hpp"

class ITickable {
    public:
        virtual void tick (SharedState & state) = 0;
};

#endif