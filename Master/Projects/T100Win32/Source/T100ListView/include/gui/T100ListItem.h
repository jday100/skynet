#ifndef T100LISTITEM_H
#define T100LISTITEM_H

#include <windows.h>
#include <commctrl.h>
#include "T100Common.h"
#include "base/T100Class.h"

class T100ListItem : public T100Class
{
    friend class T100ListView;
    public:
        T100ListItem(T100WSTRING);
        virtual ~T100ListItem();

    protected:
        LVITEMW             m_listItem;

    private:
};

#endif // T100LISTITEM_H
