#ifndef app_controller_h
#define app_controller_h

#include <mono.h>

#include "shared_state.hpp"
#include "agent.hpp"
#include "scheduler.hpp"

class AppController : public mono::IApplication {

    SharedState state;
    Scheduler   scheduler;
    Agent       agent;
    mono::Timer timer;

    void mainLoop();
    void reset();

    public:
        AppController();

        void monoWakeFromReset();
        void monoWillGotoSleep();
        void monoWakeFromSleep();
};

#endif