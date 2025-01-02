#include "T100CLParser.h"
#include "T100CLAnalyzer.h"
#include "T100CLGenerator.h"

#include "T100CLCompiler.h"

int main()
{
    T100CLParser            parser;
    T100CLAnalyzer          analyzer;
    T100CLGenerator         generator;

    T100CLCompiler          compiler;

    compiler.setParser(&parser);
    compiler.setAnalyzer(&analyzer);
    compiler.setGenerator(&generator);

    compiler.run();
}
