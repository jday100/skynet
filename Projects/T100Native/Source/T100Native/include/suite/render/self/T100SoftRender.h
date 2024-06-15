#ifndef T100SOFTRENDER_H
#define T100SOFTRENDER_H

#include "T100RenderBase.h"

class T100SoftRender : public T100RenderBase
{
    public:
        T100SoftRender();
        virtual ~T100SoftRender();

        T100VOID            Start();
        T100VOID            Stop();

    protected:

    private:
};

#endif // T100SOFTRENDER_H
