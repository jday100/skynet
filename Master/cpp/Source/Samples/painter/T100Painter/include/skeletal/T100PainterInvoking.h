#ifndef T100PAINTERINVOKING_H
#define T100PAINTERINVOKING_H

#include "T100Common.h"

class T100Painter;

class T100PainterInvoking
{
    public:
        T100PainterInvoking();
        virtual ~T100PainterInvoking();

        static T100VOID             Create(T100Painter*);
        static T100VOID             Destroy();

        static T100VOID             MenuNew();
        static T100VOID             MenuQuit();

        static T100VOID             FrameResize();

        static T100VOID             EntitySelected(T100WORD);

    protected:

    private:
        static T100Painter*         m_painterPtr;
};

#endif // T100PAINTERINVOKING_H
