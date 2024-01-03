#include "T100FileAnalyzer.h"
#include "T100FileReader.h"


T100FileAnalyzer::T100FileAnalyzer()
{
    //ctor
}

T100FileAnalyzer::~T100FileAnalyzer()
{
    //dtor
}

int T100FileAnalyzer::run(T100CmdLine& cmdline) {

    return 0;
}

int T100FileAnalyzer::load(char* file) {
    T100FileReader      reader(file);
    int result;

    //result = reader.run();

    return result;
}
