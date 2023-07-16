#include <string>
#include "../header/header.h"
void WordMachine::pointRight() {
    while(tape[finalIdx] == ' ') finalIdx++; // skip the space char
    
    size_t initIdx = finalIdx;
    while(tape[finalIdx] != ' ' && !eop()) finalIdx++; // get one tape
    cw = tape.substr(initIdx, finalIdx);
    wlen = finalIdx - initIdx;
}

void WordMachine::setTape(string src) {
    tape = src;
}

void WordMachine::setDelimiter(char src) {
    delimiter = src;
}

void WordMachine::set(string srcTape, char srcDelimiter) {
    tape = srcTape;
    delimiter = srcDelimiter;
}

void WordMachine::start() {
    finalIdx = 0;
    pointRight();
}

void WordMachine::reset() {
    start();
}

bool WordMachine::eop() {
    return (tape[finalIdx] == delimiter);
}

void WordMachine::inc() {
    pointRight();
}

size_t WordMachine::getlen() {
    return wlen;
}

string WordMachine::getcw() {
    return cw;
}

string WordMachine::getTape() {
    return tape;
}