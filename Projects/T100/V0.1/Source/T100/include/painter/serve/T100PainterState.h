#ifndef T100PAINTERSTATE_H
#define T100PAINTERSTATE_H

#include "T100State.h"
#include "T100PainterElementsPanel.h"
#include "T100PainterPropertiesPanel.h"


namespace T100Painter{

class T100PainterState : public T100Component::T100State
{
    public:
        T100PainterState();
        virtual ~T100PainterState();

        virtual T100BOOL            Create() = 0;

        //virtual T100VOID            Reset() = 0;

        virtual T100VOID            SetMenu() = 0;
        virtual T100VOID            ResetMenu() = 0;

        virtual T100PainterElementsPanel*       GetElementsPanel() = 0;
        virtual T100PainterPropertiesPanel*     GetPropertiesPanel() = 0;

    protected:

    private:
};

}

#endif // T100PAINTERSTATE_H
