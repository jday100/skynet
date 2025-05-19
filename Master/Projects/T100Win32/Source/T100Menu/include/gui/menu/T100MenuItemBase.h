#ifndef T100MENUITEMBASE_H
#define T100MENUITEMBASE_H

#include <atomic>
#include "T100Common.h"
#include "gui/common/T100MenuCommon.h"
#include "gui/control/T100Control.h"
#include "gui/font/T100Font.h"

class T100MenuItemBase : public T100Control
{
    public:
        T100MenuItemBase();
        virtual ~T100MenuItemBase();

        T100MENU_ITEM_TYPE          GetMenuItemType();

        T100VOID                    Enable();
        T100VOID                    Disable();
        T100BOOL                    IsEnabled();

        T100VOID                    SetFont(T100Font&);
        T100Font&                   GetFont();

        T100VOID                    SetHelp(T100WSTRING&);
        T100WSTRING&                GetHelp();

    protected:
        std::atomic_bool            m_enable;
        T100MENU_ITEM_TYPE          m_menuItemType;
        T100Font                    m_font;
        T100WSTRING                 m_help;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MENUITEMBASE_H
