#include "agent.hpp"
#include "settings.hpp"

using mono::geo::Point;
using mono::geo::Rect;

Agent::Agent() : View(Rect(0, 0, agentRadius * 2, agentRadius * 2)) {}

void Agent::tick(SharedState &state) {
    switch(state.simulation) {
        case SharedState::Init:
            moveTo(Point(screenHeight / 2 - agentRadius, screenWidth / 2 - agentRadius));
            state.nextState = SharedState::Running;
            return;
        
        case SharedState::Running:
            step(state);
            return;
    }
}

void Agent::step(SharedState &state) {
	if(state.msNow % delay != 0) {
		return;
	}

    Point point = decideNextPosition();
   
   	int x = point.X();
   	int y = point.Y();

    // Modolu is expensive ..
    if(x + agentRadius <= 0) {
       	x = screenWidth - agentRadius;
    } else if(x - agentRadius >= screenWidth) {
    	x = 0;
    }

    if(y + agentRadius <= 0) {
       	y = screenHeight;
    } else if(y - agentRadius >= screenHeight) {
    	y = 0;
    }

    moveTo(Point(x, y));
}

void Agent::moveTo(Point position) {
    erase();
    setPosition(position);
    repaint();
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
    // TODO: take food positions and feed to brain

    directionX = 1;
    directionY = 1;

    return effectuateDirection();
}

Point Agent::effectuateDirection() {
    int x = Position().X() + directionX;
    int y = Position().Y() + directionY;

    return Point(x, y);
}