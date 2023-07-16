#include <iostream>
#include "../header/header.h"
using namespace std;

int main() {
    WordMachine test;
    string s;
    getline(cin, s);
    test.set(s);
    test.start();
    cout << test.getcw() << "---" << test.getlen() << endl;

    while(!test.eop()) {
        test.inc();
        cout << test.getcw() << "---" << test.getlen() << endl;
    }

    return 0;
}