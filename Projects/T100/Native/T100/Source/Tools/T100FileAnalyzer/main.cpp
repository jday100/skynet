#include "T100CmdLine.h"
#include "T100FileAnalyzer.h"


int main(int argc, char** argv) {
    T100CmdLine             cmdline(argc, argv);
    T100FileAnalyzer        analyzer;

    int result;

    result = cmdline.run();

    if(0 == result){
        result = analyzer.run(cmdline);
    }

    return result;
}
