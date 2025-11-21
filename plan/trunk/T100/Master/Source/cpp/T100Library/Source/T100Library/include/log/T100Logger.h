#ifndef T100LOGGER_H
#define T100LOGGER_H

#include "log/T100LoggerBase.h"

namespace T100LIBRARY{

class T100Logger : public T100Class
{
    public:
        T100Logger();
        virtual ~T100Logger();

        virtual T100VOID            Out(const T100WSTRING&);

    protected:
        T100LoggerBase*             m_logger        = T100NULL;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

}

#endif // T100LOGGER_H
