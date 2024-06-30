#ifndef T100VIEWBASE_H
#define T100VIEWBASE_H

#include "T100Common.h"
class T100RenderBase;

class T100ViewBase
{
    public:
        T100ViewBase();
        virtual ~T100ViewBase();

        virtual T100VOID            SetRender(T100RenderBase*) = 0;
        virtual T100RenderBase*     GetRender() = 0;
        virtual T100VOID            Draw(T100VOID* = T100NULL) = 0;

    protected:
        T100INT                     m_width         = 400;
        T100INT                     m_height        = 300;

    private:
};

#endif // T100VIEWBASE_H
