#include "../header/compiler.h"

void Compiler::set_up() {
    _file.set("compiler.txt");
    _file.read();
    _compile_command = _file.getData(0); // nanti benerin yang di SequentialFile
}

void Compiler::compile() {
    system(&_compile_command[0]);
}

void Compiler::run() {
    set_up();
    compile();
}