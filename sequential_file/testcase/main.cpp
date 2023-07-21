#include <iostream>
#include "../header/header.h"
using namespace std;

int main() {
    SequentialFile a ("a.txt"), b ("b.txt");
    a.read();
    b.read();
    cout << a.compare(b) << endl;
    return 0;
}