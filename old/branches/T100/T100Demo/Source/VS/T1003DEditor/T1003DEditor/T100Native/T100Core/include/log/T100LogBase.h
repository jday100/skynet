#ifndef T100LOGBASE_H
#define T100LOGBASE_H

#include "T100Common.h"
#include "common/T100LogCommon.h"

namespace T100NATIVE{

class T100LogBase
{
    public:
        T100LogBase();
        virtual ~T100LogBase();

        virtual T100VOID            Outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE) = 0;

    protected:

    private:
};

}

#endif // T100LOGBASE_H
