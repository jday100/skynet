#ifndef T100STATEALONE_H
#define T100STATEALONE_H

#include "T100PainterState.h"

namespace T100Painter{

class T100StateAlone : public T100PainterState
{
    public:
        T100StateAlone();
        virtual ~T100StateAlone();

        T100BOOL            Create();

        T100VOID            SetMenu();
        T100VOID            ResetMenu();

        T100PainterElementsPanel*       GetElementsPanel();
        T100PainterPropertiesPanel*     GetPropertiesPanel();

    protected:

    private:
};

}

#endif // T100STATEALONE_H
