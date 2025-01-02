#include "T100Compiler.h"

#include "T100ParserInfo.h"
#include "T100AnalyzerInfo.h"
#include "T100GeneratorInfo.h"

T100Compiler::T100Compiler()
{
    //ctor
}

T100Compiler::~T100Compiler()
{
    //dtor
}

T100VOID T100Compiler::setParser(T100Parser* parser)
{
    m_parser    = parser;
}

T100Parser* T100Compiler::getParser()
{
    return m_parser;
}

T100VOID T100Compiler::setAnalyzer(T100Analyzer* analyzer)
{
    m_analyzer  = analyzer;
}

T100Analyzer* T100Compiler::getAnalyzer()
{
    return m_analyzer;
}

T100VOID T100Compiler::setGenerator(T100Generator* generator)
{
    m_generator = generator;
}

T100Generator* T100Compiler::getGenerator()
{
    return m_generator;
}

T100BOOL T100Compiler::run()
{
    T100WString             filename;
    T100WString             output;

    T100ParserInfo          parser;
    T100AnalyzerInfo        analyzer;
    T100GeneratorInfo       generator;

    filename    = "test";
    output      = "out";

    m_parser->parse(filename, parser);

    m_analyzer->analyse(parser, analyzer);

    m_generator->generate(analyzer, generator, output);
}
