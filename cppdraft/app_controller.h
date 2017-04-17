#ifndef app_controller_h
#define app_controller_h

#include <mono.h>

class AppController : public mono::IApplication {

    mono::Timer timer;

    public:
        AppController();

        void monoWakeFromReset();
        void monoWillGotoSleep();
        void monoWakeFromSleep();
};

#endif