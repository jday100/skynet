#ifndef T100PAINTERSERVE_H
#define T100PAINTERSERVE_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100PainterServe
{
    public:
        T100PainterServe();
        virtual ~T100PainterServe();

        T100VOID            Select(T100UINT);
        T100UINT&           GetCurrent();

    protected:
        T100UINT            m_current       = 0;

    private:
};

#endif // T100PAINTERSERVE_H
