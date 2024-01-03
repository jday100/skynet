#include "T100FileAnalyzer.h"
#include "T100ByteBuffer.h"
#include "T100FileReader.h"
#include "T100CodeFile.h"


T100FileAnalyzer::T100FileAnalyzer()
{
    //ctor
}

T100FileAnalyzer::~T100FileAnalyzer()
{
    //dtor
}

int T100FileAnalyzer::run(T100CmdLine& cmdline) {
    int result      = 0;

    result = load(cmdline.m_file);

    return result;
}

int T100FileAnalyzer::load(char* file) {
    int result      = 0;

    T100FileReader      reader(file);
    T100ByteBuffer      buffer(reader);
    T100CodeFile        coder(buffer);

    result = reader.open();

    if(0 == result){
        result = coder.run();
        int value = reader.close();
        result = 0 != result ? result : value;
    }

    return result;
}
