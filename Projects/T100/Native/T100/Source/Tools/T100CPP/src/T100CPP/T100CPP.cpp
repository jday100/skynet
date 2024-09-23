#include "T100CPP.h"

#include "T100CPPCompiler.h"

T100CPP::T100CPP()
{
    //ctor
}

T100CPP::~T100CPP()
{
    //dtor
}

T100BOOL T100CPP::compile(T100WString path)
{
    T100CPPCompiler         compiler;

    return compiler.done(path);
}

T100BOOL T100CPP::decompile(T100WString path)
{
    return T100FALSE;
}
