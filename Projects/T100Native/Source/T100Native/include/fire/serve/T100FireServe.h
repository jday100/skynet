#ifndef T100FIRESERVE_H
#define T100FIRESERVE_H

#include "T100Render.h"

class T100FireServe
{
    public:
        T100FireServe();
        virtual ~T100FireServe();

        T100VOID                SetRender(T100Render*);
        T100Render*             GetRender();

    protected:
        T100Render*             m_render            = T100NULL;

    private:
        T100VOID                TurnOn();
        T100VOID                TurnOff();
};

#endif // T100FIRESERVE_H
