#include <iostream>
#include "../header/header.h"
#include <filesystem>
using namespace std;

int main() {
    ProgramTester programTester;

    string compile_command, programName;
    getline(cin, compile_command);
    getline(cin, programName);
    programTester.compile(compile_command);

    string inputPath, outputPath;
    getline(cin, inputPath);
    getline(cin, outputPath);
    size_t inputPathLen = inputPath.size();

    double timelimit;
    cin >> timelimit;
    programTester.setTimelimit(timelimit);
    
    string curPath, filename;
    for (const auto & entry : std::filesystem::directory_iterator(inputPath)) {
        curPath = entry.path();
        filename = curPath.substr(inputPathLen);

        programTester.runTest(programName, curPath, outputPath + filename);

        cout << filename << "\n";
        cout << "OUTPUT : " << programTester.getACResult() << " "
             << programTester.getLastCheckIterator() << "\n";
        cout << "TIME   : " << programTester.getTLEResult() << " "
             << fixed << setprecision(6) << programTester.getDuration() << "\n\n";
    }
    return 0;
}