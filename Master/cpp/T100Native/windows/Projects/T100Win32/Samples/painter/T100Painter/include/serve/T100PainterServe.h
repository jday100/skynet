#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include "T100Common.h"

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100VOID            Select(T100WORD);
        T100WORD&           GetCurrent();

    protected:
        T100WORD            m_current       = 0;

    private:
};

#endif // T100PAINTERSERVE_H
