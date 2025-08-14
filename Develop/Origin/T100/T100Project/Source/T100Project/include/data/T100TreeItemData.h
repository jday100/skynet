#ifndef T100TREEITEMDATA_H
#define T100TREEITEMDATA_H

#include <atomic>
#include <wx/menu.h>
#include <wx/treectrl.h>
#include "T100Common.h"

class T100TreeItemData : public wxTreeItemData
{
    public:
        T100TreeItemData();
        virtual ~T100TreeItemData();

        T100VOID                    SetOpened(T100BOOL);

        virtual wxMenu*             ShowMenu() = 0;

        virtual T100VOID            OnItemChanged() = 0;

        virtual T100VOID            OnItemActivated() = 0;

        virtual T100VOID            OnItemExpanding() = 0;

    protected:
        std::atomic_bool            m_opened;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100TREEITEMDATA_H
