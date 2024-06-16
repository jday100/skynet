#ifndef T100RENDERBASE_H
#define T100RENDERBASE_H

#include "T100Common.h"

class T100RenderBase
{
    public:
        T100RenderBase();
        virtual ~T100RenderBase();

        virtual T100BYTE*           GetData() = 0;

        virtual T100VOID            Start() = 0;
        virtual T100VOID            Stop() = 0;

        virtual T100VOID            Draw() = 0;

        virtual T100VOID            SetSize(T100INT, T100INT) = 0;

        virtual T100INT             GetWidth() = 0;
        virtual T100INT             GetHeight() = 0;

    protected:

    private:
};

#endif // T100RENDERBASE_H
