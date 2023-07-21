#include <string>
#include <vector>
#include "../header/header.h"

void ProgramTester::set(std::string programPath, std::string input, std::string expected_output, std::string obtained_output) {
    /* Prepare the program */
    _program_path = programPath;

    /* Prepare the input */
    _input.set(input);
    _input.read();

    /* Prepare the expected output */
    _expected_output.set(expected_output);
    _expected_output.read();
    _expected_line_totals = _expected_output.getTotalUnits();

    std::vector<bool> output_similarity (_expected_line_totals + 1, 1);
    _output_similarity = output_similarity;

    /* Prepare the obtained output */
    _obtained_output.set(obtained_output);
}

void ProgramTester::speedTest() {
    /*
     * run program, count duration, and obtain output
     */
    std::string command = _program_path + " < " + _input.getPath() + " > " + _obtained_output.getPath();

    _duration.start();      // duration counter
    system(&command[0]);    // run program and obtain output
    _duration.stop();       // duration counter

    _obtained_line_totals = _obtained_output.getTotalUnits();   // obtain total line of output
}

void ProgramTester::caseTest(bool runProgramCondition) {
    /*
     * run program if the condition is true
     */
    if(runProgramCondition) {
        std::string command = _program_path + " < " + _input.getPath() + " > " + _obtained_output.getPath();

        system(&command[0]);                                        // run program and obtain output
        _obtained_line_totals = _obtained_output.getTotalUnits();   // obtain total line of output
    }

    /*
     * check similarity
     */
    std::string _expected_line_output, _obtained_line_output;
    unsigned long _iterator = 0;
    while(_iterator < _expected_line_totals && _iterator < _obtained_line_totals) {
        _expected_line_output = _expected_output.getData(_iterator);
        _obtained_line_output = _obtained_output.getData(_iterator);

        if(_expected_line_output.compare(_obtained_line_output) == 0) _output_similarity[_iterator] = 0;

        _iterator++;
    }

    while(_iterator < _expected_line_totals) _output_similarity[_iterator] = 0;
    if(_iterator < _obtained_line_totals) _output_similarity[_iterator] = 0;
}

void ProgramTester::test() {
    speedTest();
    caseTest();
}