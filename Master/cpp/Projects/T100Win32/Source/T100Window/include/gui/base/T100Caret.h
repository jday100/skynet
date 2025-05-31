#ifndef T100CARET_H
#define T100CARET_H

#include "base/T100Class.h"
#include "gui/base/T100Size.h"
#include "gui/base/T100Point.h"
#include "gui/window/T100Window.h"

class T100Caret : public T100Class
{
    public:
        T100Caret(T100Window*);
        virtual ~T100Caret();

        T100VOID            SetSize(T100Size);
        T100Size&           GetSize();

        T100VOID            SetPosition(T100Point);
        T100Point&          GetPosition();

        T100VOID            SetBlinkTime(T100INT);
        T100INT             GetBlinkTime();

        T100VOID            Hide();
        T100VOID            Show();
        T100BOOL            IsShown();

        T100VOID            Move(T100INT, T100INT);

    protected:

    private:
        T100Window*         m_window            = T100NULL;
        T100Size            m_size;
        T100Point           m_position;

        T100INT             m_blinkTime         = 0;
};

#endif // T100CARET_H
