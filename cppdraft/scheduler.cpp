#include "scheduler.hpp"

Scheduler::Scheduler() {}

void Scheduler::add(ITickable *tickable) {
    tickables.push_back(tickable);
}

void Scheduler::run(SharedState &state) {
	state.simulation = state.nextState;
    for(std::vector<ITickable*>::iterator i = tickables.begin(); i != tickables.end(); ++i) {
        (*i) -> tick(state);
    }
}