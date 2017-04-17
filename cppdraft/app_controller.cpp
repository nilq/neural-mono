#include "app_controller.h"
#include "settings.hpp"

AppController::AppController() : timer(msResolution) {
    scheduler.add(&agent);
}

void AppController::reset() {
    state.reset();
    timer.setCallback(this, &AppController::mainLoop);
    timer.Start();
}

void AppController::mainLoop() {
    scheduler.run(state);
}

void AppController::monoWakeFromReset() {
    reset();
}

void AppController::monoWillGotoSleep() {
    timer.Stop();
}

void AppController::monoWakeFromSleep() {
    reset();
}