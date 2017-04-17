#ifndef scheduler_h
#define scheduler_h

#include <mono.h>

#include <vector>
#include "shared_state.hpp"
#include "itickable.hpp"

class Scheduler {
    std::vector<ITickable> tickables;

    public:
         Scheduler();
         void add(ITickable *);
         void run(SharedState &);
};

#endif
