#ifndef T100PAINTERENTITYPANEL_H
#define T100PAINTERENTITYPANEL_H

#include "gui/T100Panel.h"
#include "gui/T100ListView.h"
#include "gui/T100AllEvents.h"

using namespace T100LIBRARY;
using namespace T100WINDOWS;

class T100PainterEntityPanel : public T100Panel
{
    public:
        T100PainterEntityPanel();
        T100PainterEntityPanel(T100Window*);
        virtual ~T100PainterEntityPanel();

        T100VOID            Create(T100Window*, T100WSTRING, T100PanelStyle*);

    protected:
        T100ListView        m_listView;

        T100VOID            OnListViewItemSelected(T100NotifyEvent&);

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PAINTERENTITYPANEL_H
