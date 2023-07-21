#include "../header/compiler.h"
#include "../header/executor.h"

class ProgramTester:public Compiler, public Executor {
    private:
        Compiler _compiler;
        Executor _exc_container;
        
        void run_task();
        void show_result();
    
    public:
        void run();
};