#include <iostream>
#include "../header/header.h"
using namespace std;

int main() {
    string path;
    SequentialFile file;
    cin >> path;
    file.set(path);
    file.read();
    for(int i = 0; i < file.getTotalUnits(); i++) cout << file.getData(i) << endl;
    return 0;
}