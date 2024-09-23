#include "T100CPPParser.h"

#include "T100CPPScanner.h"

T100CPPParser::T100CPPParser()
{
    //ctor
}

T100CPPParser::~T100CPPParser()
{
    //dtor
}

T100BOOL T100CPPParser::done(T100WString path)
{
    T100CPPScanner          scanner;

    return scanner.done(path);
}
