#ifndef T100MENUITEMBASE_H
#define T100MENUITEMBASE_H

#include <atomic>
#include "T100Common.h"
#include "gui/T100Win32Common.h"
#include "gui/T100Font.h"

class T100MenuItemBase
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

        T100BOOL                    IsCheckable();

    protected:
        std::atomic_bool            m_enable;
        std::atomic_bool            m_checkable;
        T100MENU_ITEM_TYPE          m_type;
        T100Font                    m_font;
        T100WSTRING                 m_help;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100MENUITEMBASE_H
