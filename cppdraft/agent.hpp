#ifndef agent_h
#define agent_h

#include <mono.h>
#include "itickable.hpp"

class Agent : public ITickable, public mono::ui::View {
    int directionX;
    int directionY;

    void reset();
    void erase();
    void moveTo(mono::geo::Point position, uint16_t &x);

    mono::geo::Point decideNextPosition();
    mono::geo::Point effectuateDirection();

    public:
        virtual void repaint();
        virtual char const *getName() const {
            return "Agent";
        };

        virtual void tick(SharedState &state);
};

#endif