#ifndef T100PROJECTMAINMENUACTUATOR_H
#define T100PROJECTMAINMENUACTUATOR_H

#include "gui/handler/T100EventHandler.h"

using namespace T100WINDOWS;

class T100ProjectMainMenuActuator : public T100EventHandler
{
    public:
        T100ProjectMainMenuActuator(T100EventHandler*);
        virtual ~T100ProjectMainMenuActuator();

        T100VOID            OnNew(T100MenuEvent&);
        T100VOID            OnOpen(T100MenuEvent&);
        T100VOID            OnClose(T100MenuEvent&);
        T100VOID            OnSave(T100MenuEvent&);
        T100VOID            OnSaveAs(T100MenuEvent&);
        T100VOID            OnQuit(T100MenuEvent&);

        T100VOID            OnUndo(T100MenuEvent&);
        T100VOID            OnRedo(T100MenuEvent&);
        T100VOID            OnCut(T100MenuEvent&);
        T100VOID            OnCopy(T100MenuEvent&);
        T100VOID            OnPaste(T100MenuEvent&);

        T100VOID            OnFind(T100MenuEvent&);
        T100VOID            OnReplace(T100MenuEvent&);

        T100VOID            OnAbout(T100MenuEvent&);

    protected:

    private:
};

#endif // T100PROJECTMAINMENUACTUATOR_H
