#include "shared_state.hpp"
#include "settings.hpp"

SharedState::SharedState() {
    reset();
}

void SharedState::reset() {
    simulation = Init;
    nextState  = simulation;

    msNow  = 0;
    agentX = 0;
}

bool SharedState::operator == (SharedState const &rhs) const {
    return nextState == rhs.nextState && simulation == rhs.simulation;
}

bool SharedState::operator != (SharedState const &rhs) const {
    return !((*this) == rhs);
}