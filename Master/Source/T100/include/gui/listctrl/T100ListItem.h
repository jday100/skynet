#ifndef T100LISTITEM_H
#define T100LISTITEM_H

#include <windows.h>
#include <commctrl.h>
#include "T100Common.h"

class T100ListItem
{
    friend class T100ListCtrl;
    public:
        T100ListItem(T100WSTRING);
        virtual ~T100ListItem();

    protected:
        LVITEMW         m_listItem;

    private:
};

#endif // T100LISTITEM_H
