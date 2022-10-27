#ifndef T100LOGBASE_H
#define T100LOGBASE_H

#include "T100SourceTypes.h"
#include "T100LogCommon.h"

namespace T100Library{

class T100LogBase : public T100Class
{
    public:
        T100LogBase();
        virtual ~T100LogBase();

        virtual T100VOID            outline(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE source = T100SOURCE_NONE) = 0;

    protected:

    private:
};

}

#endif // T100LOGBASE_H
