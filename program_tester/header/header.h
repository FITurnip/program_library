// ================================
// GUARD MASTER HEADER
#ifndef __PROGRAM_TESTER_INCLUDED__
#define __PROGRAM_TESTER_INCLUDED__

// ================================
// DEPENDENCIES LIBRARY
#include "../../library/sequential_file.h"
#include "duration_counter.h"

// ================================
// ACTUAL HEADER CONTENT
class ProgramTester: public SequentialFile, public DurationCounter {
    private:
        /* Program */
        std::string _program_path;

        /* Input Output */
        SequentialFile _input, _expected_output, _obtained_output;
        std::vector<bool> _output_similarity;
        std::size_t _expected_line_totals, _obtained_line_totals;

        /* Duration */
        DurationCounter _duration;

    public:
        /* SET */
        void set(std::string, std::string, std::string, std::string);

        /* TEST */
        void speedTest();
        void caseTest(bool = 0);
        void test();
};

#endif // __PROGRAM_TESTER_INCLUDED__