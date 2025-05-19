#ifndef T100LOGBASE_H
#define T100LOGBASE_H

#include "common/T100SourceTypes.h"
#include "common/T100LogCommon.h"
#include "base/T100Class.h"

class T100LogBase : public T100Class
{
    public:
        T100LogBase();
        virtual ~T100LogBase();

        virtual T100VOID            OutLine(T100LOG_TYPE, T100WSTRING&, T100SOURCE_TYPE = T100SOURCE_NONE) = 0;

    protected:

    private:
};

#endif // T100LOGBASE_H
