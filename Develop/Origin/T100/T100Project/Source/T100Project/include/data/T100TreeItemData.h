#ifndef T100TREEITEMDATA_H
#define T100TREEITEMDATA_H

#include <wx/menu.h>
#include <wx/treectrl.h>
#include "T100Common.h"

class T100TreeItemData : public wxTreeItemData
{
    public:
        T100TreeItemData();
        virtual ~T100TreeItemData();

        virtual wxMenu*         ShowMenu() = 0;

        virtual T100VOID        OnItemActivated() = 0;

        virtual T100VOID        OnItemExpanding() = 0;

    protected:

    private:
};

#endif // T100TREEITEMDATA_H
