#ifndef T100PROJECTMAINMENUACTUATOR_H
#define T100PROJECTMAINMENUACTUATOR_H

#include "gui/handler/T100EventHandler.h"

using namespace T100WINDOWS;

class T100ProjectMainMenuActuator : public T100EventHandler
{
    public:
        T100ProjectMainMenuActuator(T100EventHandler*);
        virtual ~T100ProjectMainMenuActuator();

        T100VOID            OnQuit(T100WindowEvent&);

    protected:

    private:
};

#endif // T100PROJECTMAINMENUACTUATOR_H
