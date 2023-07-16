using namespace std;
class WordMachine {
    string tape, cw;
    char delimiter;
    size_t finalIdx, wlen;

    void pointRight();

    public:
    void setTape(string);
    void setDelimiter(char);
    void set(string, char = 0);

    void start();
    void reset();
    bool eop();

    void inc();
    size_t getlen();
    string getcw();
    string getTape();
};