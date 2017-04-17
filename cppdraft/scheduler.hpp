#ifndef scheduler_h
#define scheduler_h

#include <mono.h>
#include "itickable.hpp"

class Scheduler {
    std::vector<ITickable> tickables;

    public:
         Scheduler();
         void add(ITickable *);
         void run(SharedState &);
};

#endif
