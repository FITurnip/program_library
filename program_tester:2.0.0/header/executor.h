#include <vector>
#include <string>
#include <filesystem>
#include "../header/duration_counter.h"
#include "../header/similarity_checker.h"
#include "../../library/sequential_file.h"

class Executor: public SequentialFile, public DurationCounter, public SimilarityChecker  {
    private:
        struct Case {
            SequentialFile _input, _output;
            double _execution_time;
        };

        struct Result {
            SequentialFile _output;
            DurationCounter _duration_counter;
            double _execution_time;
            SimilarityChecker _similarity_checker;
        };

        struct Container {
            Case _case;
            Result _result;
        };

        std::string _testcase_dir = "testcase/";
        std::vector<Container> _container;
        std::vector<std::string> _filename;
        size_t _totalCase;

    public:
        void setTimelimit();
        void setCase();
        void set();
        
        void runDurationCounter(unsigned long &itr);
        void runSimilarityChecker(unsigned long &itr);
        void run();
};