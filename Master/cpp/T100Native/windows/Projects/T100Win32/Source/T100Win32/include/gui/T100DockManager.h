#ifndef T100DOCKMANAGER_H
#define T100DOCKMANAGER_H

#include "gui/dock/T100DockManagerBase.h"

namespace T100WINDOWS{

class T100DockManager : public T100DockManagerBase
{
    public:
        T100DockManager();
        T100DockManager(T100Frame*);
        virtual ~T100DockManager();

        virtual T100VOID            Update();
        virtual T100VOID            AddPane(const T100WSTRING&, T100Window*, T100DockInfo&);

    protected:

    private:
};

}

#endif // T100DOCKMANAGER_H
