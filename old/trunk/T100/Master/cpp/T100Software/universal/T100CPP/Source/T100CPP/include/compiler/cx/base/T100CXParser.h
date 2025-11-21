#ifndef T100CXPARSER_H
#define T100CXPARSER_H

#include "compiler/base/T100Parser.h"

using namespace T100LIBRARY;

class T100CXParser : public T100Parser
{
    public:
        T100CXParser();
        virtual ~T100CXParser();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CXPARSER_H
