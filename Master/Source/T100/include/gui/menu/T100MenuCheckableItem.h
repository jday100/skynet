#ifndef T100MENUCHECKABLEITEM_H
#define T100MENUCHECKABLEITEM_H

#include "gui/menu/T100MenuItem.h"

class T100MenuCheckableItem : public T100MenuItem
{
    public:
        T100MenuCheckableItem(T100Menu*, T100UINT, T100WSTRING, T100BOOL = T100FALSE);
        virtual ~T100MenuCheckableItem();

        T100BOOL                    IsChecked();

    protected:
        std::atomic_bool            m_checked;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MENUCHECKABLEITEM_H
