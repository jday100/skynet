#ifndef T100CXFRONTEND_H
#define T100CXFRONTEND_H

#include "compiler/base/T100FrontEnd.h"

using namespace T100LIBRARY;

class T100CXFrontEnd : public T100FrontEnd
{
    public:
        T100CXFrontEnd();
        virtual ~T100CXFrontEnd();

    protected:

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100CXFRONTEND_H
