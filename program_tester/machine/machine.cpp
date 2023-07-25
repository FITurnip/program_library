#include "../header/header.h"

/* Set Up */
void ProgramTester::compile(std::string command) {
    system(&command[0]);
}
void ProgramTester::setTimelimit(double seconds) {
    timelimit = seconds;
}

/* Get Result */
std::string ProgramTester::getResult(int cond) {
    switch(cond) {
        case 0: return "\033[41;37mFAIL\033[0m";
        case 1: return "\033[42;37mPASS\033[0m";
    }
    return "\033[47;30mProgram is not running\033[0m";
}

std::string ProgramTester::getTLEResult() {
    return getResult(TLE);
}

std::string ProgramTester::getACResult() {
    return getResult(AC);
}

double ProgramTester::getDuration() {
    return duration;
}

unsigned long ProgramTester::getLastCheckIterator() {
    return lastCheckIterator;
}

/* Count Duration */
void ProgramTester::startTimer() {
    time_start = clock();
}

void ProgramTester::endTimer() {
    time_end = clock();
    duration = ((double)time_end - time_start)/CLOCKS_PER_SEC;
}

/* Run One Test */
void ProgramTester::runProgram(std::string program, std::string input) {
    std::string command = program + " < " + input + " > " + "result.txt";
    system(&command[0]);
}

void ProgramTester::runTest(std::string program, std::string input, std::string output) {
    TLE = -1; AC = -1; lastCheckIterator = 0;
    startTimer();
    runProgram(program, input);
    endTimer();

    SequentialFile expected (output), result ("result.txt");
    fileExist = expected.read();
    result.read();

    if(!fileExist) return;
    AC = expected.compare(result);
    TLE = (duration < timelimit ? 1 : 0);
    lastCheckIterator = expected.getLastCheckIterator();
}
