#include <string>
#include "../../library/sequential_file.h"

class Compiler: public SequentialFile {
    private:
        SequentialFile _file;
        std::string _compile_command;

        void set_up();
        void compile();
    
    public:
        void run();
};