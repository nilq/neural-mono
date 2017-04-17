#include "agent.hpp"
#include "settings.hpp"

using mono::geo::Point;
using mono::geo::Rect;

Agent::Agent() : View(Rect(0, 0, agentRadius * 2, agentRadius * 2)) {}

void Agent::tick(SharedState &state) {
    switch(state.simulation) {
        case SharedState::Init:
            moveTo(Point(screenHeight / 2 - agentRadius, screenWidth / 2 - agentRadius), state.agentX);
            return;
        
        case SharedState::Running:
            step();
            return;
    }

    directionX = 1;
    directionY = 0;
    return;
}

void Agent::step(SharedState &state) {
    moveTo(decideNextPosition(), state.agentX);
}

void Agent::moveTo(Point position, uint16_t &x) {
    erase();
    setPosition(position);
    repaint();

    x = position.X();
}

void Agent::erase () {
  painter.setForegroundColor(black);
  painter.drawFillRect(ViewRect().X(), ViewRect().Y(), agentRadius * 2, agentRadius * 2);
}

void Agent::repaint () {
  painter.setForegroundColor(green);
  painter.drawFillRect(ViewRect().X(), ViewRect().Y(), agentRadius * 2, agentRadius * 2);
}

Point Agent::decideNextPosition() {
    int x = Position().X();
    int y = Position().Y();

    // TODO: take food positions and feed to brain

    return effectuateDirection();
}

Point Agent::effectuateDirection() {
    int x = Position().X() + directionX;
    int y = Position().Y() + directionY;

    return Point(x, y);
}