#ifndef T100TREEITEM_H
#define T100TREEITEM_H

#include <windows.h>
#include <commctrl.h>
#include "T100Common.h"

class T100TreeItem
{
    friend class T100TreeCtrl;
    public:
        T100TreeItem(T100WSTRING);
        virtual ~T100TreeItem();

    protected:
        TVITEMW             m_treeItem;

    private:
};

#endif // T100TREEITEM_H
