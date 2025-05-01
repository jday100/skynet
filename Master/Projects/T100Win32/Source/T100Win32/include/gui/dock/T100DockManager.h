#ifndef T100DOCKMANAGER_H
#define T100DOCKMANAGER_H

#include "gui/dock/T100DockManagerBase.h"

class T100DockManager : public T100DockManagerBase
{
    public:
        T100DockManager();
        T100DockManager(T100Frame*);
        virtual ~T100DockManager();

        T100VOID                        AddPane(T100WSTRING, T100Window*, T100DockInfo&);

        T100VOID                        Update();



    protected:

    private:
};

#endif // T100DOCKMANAGER_H
