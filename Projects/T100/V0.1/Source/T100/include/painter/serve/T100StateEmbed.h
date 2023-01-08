#ifndef T100STATEEMBED_H
#define T100STATEEMBED_H

#include "T100PainterState.h"


namespace T100Painter{

class T100StateEmbed : public T100PainterState
{
    public:
        T100StateEmbed();
        virtual ~T100StateEmbed();

        T100BOOL            Create();

        T100VOID            SetMenu();
        T100VOID            ResetMenu();

        T100PainterElementsPanel*       GetElementsPanel();
        T100PainterPropertiesPanel*     GetPropertiesPanel();

    protected:

    private:
};

}

#endif // T100STATEEMBED_H
