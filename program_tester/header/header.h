// ================================
// GUARD MASTER HEADER
// ================================
#ifndef __PROGRAM_TESTER_INCLUDED__
#define __PROGRAM_TESTER_INCLUDED__

// ================================
// DEPENDENCIES HEADER
// ================================
#include "../../master/sequential_file.h"
#include <stdlib.h>
#include <time.h>

// ================================
// ACTUAL HEADER CONTENT
// ================================
class ProgramTester: SequentialFile {
    private:
        /* Result */
        bool fileExist;
        int TLE, AC;
        unsigned long lastCheckIterator;

        /* Duration */
        time_t time_start, time_end;
        double duration, timelimit;

        /* Count Duration */
        void startTimer();
        void endTimer();

        /* Get Result */
        std::string getResult(int cond);
    public:
        /* Set Up */
        void compile(std::string command);
        void setTimelimit(double seconds);

        /* Get Result */
        std::string getTLEResult();
        std::string getACResult();
        double getDuration();
        unsigned long getLastCheckIterator();

        /* Run One Test */
        void runProgram(std::string program, std::string input);
        void runTest(std::string program, std::string input, std::string output);
};

#endif // __PROGRAM_TESTER_INCLUDED__