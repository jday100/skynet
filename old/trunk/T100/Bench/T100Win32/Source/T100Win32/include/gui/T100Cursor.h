#ifndef T100CURSOR_H
#define T100CURSOR_H

#include "base/T100Size.h"
#include "base/T100Point.h"
#include "gui/T100Window.h"

namespace T100WINDOWS{

class T100Cursor : public T100Class
{
    public:
        T100Cursor(T100Window*);
        virtual ~T100Cursor();

        T100VOID                SetSize(const T100Size&);
        const T100Size&         GetSize();

        T100VOID                SetPosition(const T100Point&);
        const T100Point&        GetPosition();

        T100VOID                SetBlinkTime(T100INT);
        T100INT                 GetBlinkTime();

        T100VOID                Show();
        T100VOID                Hide();
        T100BOOL                IsShown();

        T100VOID                Move(T100INT, T100INT);

    protected:
        T100Window*             m_window        = T100NULL;
        T100Size                m_size;
        T100Point               m_position;

        T100INT                 m_blinkTime     = 0;

    private:
};

}

#endif // T100CURSOR_H
