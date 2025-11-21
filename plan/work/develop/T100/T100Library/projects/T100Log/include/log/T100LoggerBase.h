#ifndef T100LOGGERBASE_H
#define T100LOGGERBASE_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100LoggerBase : public T100Class
{
    public:
        T100LoggerBase();
        virtual ~T100LoggerBase();

        virtual T100VOID            Out(const T100WSTRING&) = 0;

    protected:

    private:
};

}

#endif // T100LOGGERBASE_H
