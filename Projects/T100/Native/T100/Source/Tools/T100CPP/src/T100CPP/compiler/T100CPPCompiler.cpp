#include "T100CPPCompiler.h"

#include "T100CPPParser.h"
#include "T100CPPGenerator.h"

T100CPPCompiler::T100CPPCompiler()
{
    //ctor
}

T100CPPCompiler::~T100CPPCompiler()
{
    //dtor
}

T100BOOL T100CPPCompiler::done()
{
    T100CPPParser           parser;
    T100CPPGenerator        generator;

    T100BOOL                result          = T100FALSE;

    result  = parser.done();

    if(result){
        result  = generator.done();
    }

    return result;
}
