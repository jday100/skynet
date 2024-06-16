#ifndef T100FIRE_H
#define T100FIRE_H

#include "T100Game.h"
#include "T100NativeMain.h"

#include "T100FireStore.h"
#include "T100FireServe.h"
#include "T100FireView.h"

class T100Fire : public T100Game
{
    public:
        T100Fire();
        virtual ~T100Fire();

        T100VOID                Show();

        T100NativeFrame*        GetFrame();

    protected:
        T100FireStore*          m_store         = T100NULL;
        T100FireServe*          m_serve         = T100NULL;
        T100FireView*           m_view          = T100NULL;

    private:
        T100VOID                TurnOn();
        T100VOID                TurnOff();
};

#endif // T100FIRE_H
