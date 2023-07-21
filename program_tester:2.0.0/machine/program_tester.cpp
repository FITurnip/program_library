// #include "../header/compiler.h"
// #include "../header/executor.h"
#include "../header/program_tester.h"

#define PT ProgramTester
void PT::run_task() {
    _compiler.run();
    _exc_container.set();
}

void PT::show_result() {
}

void PT::run() {
    run_task();
    show_result();
}

#undef PT