#include "../header/executor.h"

#define _CASE(idx) _container[idx]._case
#define _RESULT(idx) _container[idx]._result

void Executor::setTimelimit() {
    SequentialFile _file;
    _file.set("timelimit.txt");
    _file.read();
    for(unsigned long i = 0; i < _totalCase; i++) _CASE(i)._execution_time = stod(_file.getData(i));
}

void Executor::setCase() {
    for(unsigned long i = 0; i < _totalCase; i++) {
        _CASE(i)._input.set("testcase/input/" + _filename[i], '\n');
        _CASE(i)._input.read();
        
        _CASE(i)._output.set("testcase/output/" + _filename[i], '\n');
        _CASE(i)._output.read();

        _CASE(i)._output.set("result/" + _filename[i], '\n');
    }
}

void Executor::set() {
    for(const auto & _file: std::filesystem::__cxx11::recursive_directory_iterator("testcase/"))
        _filename.push_back(_file.path());

    _totalCase = _filename.size();

    setTimelimit();
    setCase();
}

void Executor::runDurationCounter(unsigned long &idx) {
    std::string _command = "./a.out < testcase/" + _filename[idx] + " > result/";
    _RESULT(idx)._duration_counter.start();
    system(&_command[0]);
    _RESULT(idx)._duration_counter.stop();
    _RESULT(idx)._execution_time = _RESULT(idx)._duration_counter.getDuration();
}

void Executor::runSimilarityChecker(unsigned long &idx) {
    std::vector<std::string> _case_output = _CASE(idx)._output.getAll(), _result_output = _RESULT(idx)._output.getAll();
    _RESULT(idx)._similarity_checker.checkSimilarity(_case_output, _result_output);
}

void Executor::run() {
    for(unsigned long itr = 0; itr < _totalCase; itr++) {
        runDurationCounter(itr);
        runSimilarityChecker(itr);
    }
}

#undef _CASE
#undef _RESULT

// int main() {
//     return 0;
// }