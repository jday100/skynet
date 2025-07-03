#ifndef T100CXCOMPILER_H
#define T100CXCOMPILER_H

#include "compiler/base/T100Compiler.h"

using namespace T100LIBRARY;

class T100CXCompiler : public T100Compiler
{
    public:
        T100CXCompiler();
        virtual ~T100CXCompiler();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CXCOMPILER_H
