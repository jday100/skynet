#ifndef T100CPPCOMPILER_H
#define T100CPPCOMPILER_H

#include "T100Common.h"
#include "T100WString.h"

class T100CPPCompiler
{
    public:
        T100CPPCompiler();
        virtual ~T100CPPCompiler();

        T100BOOL            done(T100WString);

    protected:

    private:
};

#endif // T100CPPCOMPILER_H
