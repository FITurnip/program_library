// ================================
// DEPENDENCIES HEADER
// ================================
#include <string>
#include "../header/header.h"

/**********************************
 * Set value
 **********************************/
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

/**********************************
 * On off machine
 **********************************/
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

/**********************************
 * Point the word
 **********************************/
void WordMachine::inc() {
    pointRight();
}

void WordMachine::pointRight() {
    // skip the space char
    while(tape[finalIdx] == ' ') finalIdx++;
    
    // get final of word
    size_t initIdx = finalIdx;
    while(tape[finalIdx] != ' ' && !eop()) finalIdx++;
    cw = tape.substr(initIdx, finalIdx);
    wlen = finalIdx - initIdx;
}

/**********************************
 * Get property
 **********************************/
size_t WordMachine::getlen() {
    return wlen;
}

string WordMachine::getcw() {
    return cw;
}

string WordMachine::getTape() {
    return tape;
}