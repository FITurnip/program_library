// ================================
// GUARD MASTER HEADER
// ================================
#ifndef __WORD_MACHINE_INCLUDED__
#define __WORD_MACHINE_INCLUDED__

// ================================
// ACTUAL HEADER CONTENT
// ================================
using namespace std;
class WordMachine {
    private:
        /* Property */
        string tape, cw;
        char delimiter;
        size_t finalIdx, wlen;

        /* Point the word */
        void pointRight();

    public:
        /* Set value */
        void setTape(string);
        void setDelimiter(char);
        void set(string, char = 0);

        /* On off machine */
        void start();
        void reset();
        bool eop();

        /* Point the word */
        void inc();

        /* Get property */
        size_t getlen();
        string getcw();
        string getTape();
};

#endif // __WORD_MACHINE_INCLUDED__