#ifndef itickable_h
#define itickable_h

#include "shared_state.hpp"

class ITickable {
    public:
        virtual char const * getName () const = 0;
        virtual void tick (SharedState & state) const = 0;
};

#endif