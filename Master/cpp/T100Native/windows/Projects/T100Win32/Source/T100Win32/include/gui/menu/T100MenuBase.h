#ifndef T100MENUBASE_H
#define T100MENUBASE_H

#include "gui/T100Font.h"
#include "gui/control/T100Control.h"

namespace T100WINDOWS{

class T100MenuBase : public T100Control
{
    friend class T100Menu;
    friend class T100MenuItem;
    public:
        T100MenuBase();
        virtual ~T100MenuBase();

        HMENU                       GetHMENU();

        T100VOID                    Enable();
        T100VOID                    Disable();
        T100BOOL                    IsEnabled();

        T100VOID                    SetFont(const T100Font&);
        const T100Font&             GetFont();

        T100VOID                    SetHelp(const T100WSTRING&);
        const T100WSTRING&          GetHelp();

    protected:
        HMENU                       m_menu;
        T100Font                    m_font;
        T100WSTRING                 m_help;

    private:
};

}

#endif // T100MENUBASE_H
