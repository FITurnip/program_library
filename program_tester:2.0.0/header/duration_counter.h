// ================================
// GUARD MASTER HEADER
#ifndef __DURATION_COUNTER_INCLUDED__
#define __DURATION_COUNTER_INCLUDED__

#include <ctime>

// ================================
// ACTUAL HEADER CONTENT
class DurationCounter {
    private:
        clock_t _start, _end;
        double _duration = 0;

    public:
        void start();
        void stop();
        double getDuration();
};

#endif // __DURATION_COUNTER_INCLUDED__