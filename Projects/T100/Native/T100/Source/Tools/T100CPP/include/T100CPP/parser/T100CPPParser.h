#ifndef T100CPPPARSER_H
#define T100CPPPARSER_H

#include "T100Common.h"
#include "T100WString.h"

class T100CPPParser
{
    public:
        T100CPPParser();
        virtual ~T100CPPParser();

        T100BOOL            done(T100WString);

    protected:

    private:
};

#endif // T100CPPPARSER_H
