#include <ctime>
#include "../header/duration_counter.h"

void DurationCounter::start() {
    _start = clock();
}

void DurationCounter::stop() {
    _end = clock();

    _duration = _end - _start;
}

double DurationCounter::getDuration() {
    return _duration;
}