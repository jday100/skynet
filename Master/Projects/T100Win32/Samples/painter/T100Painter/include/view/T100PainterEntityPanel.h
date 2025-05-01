#ifndef T100PAINTERENTITYPANEL_H
#define T100PAINTERENTITYPANEL_H

#include "gui/T100Panel.h"
#include "gui/listctrl/T100ListCtrl.h"

class T100PainterEntityPanel : public T100Panel
{
    public:
        T100PainterEntityPanel();
        virtual ~T100PainterEntityPanel();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);

    protected:
        T100ListCtrl        m_listCtrl;

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100PAINTERENTITYPANEL_H
