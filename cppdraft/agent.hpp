#ifndef agent_h
#define agent_h

#include <mono.h>

#include "itickable.hpp"
#include "rng.hpp"

class Agent : public ITickable, public mono::ui::View {
    Rng rng;

    int directionX;
    int directionY;

    void reset();
    void erase();
    void moveTo(mono::geo::Point position);
    void step(SharedState &state);

    mono::geo::Point decideNextPosition();
    mono::geo::Point effectuateDirection();

    public:
        Agent();
        virtual void repaint();
        virtual void tick(SharedState &state);
};

#endif