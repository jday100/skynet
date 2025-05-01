#ifndef T100LISTCTRL_H
#define T100LISTCTRL_H

#include "gui/T100Window.h"

class T100ListCtrl : public T100Window
{
    public:
        T100ListCtrl();
        virtual ~T100ListCtrl();

        T100VOID            Create(T100Window*);

        T100VOID            Append(T100WSTRING);

    protected:

    private:
};

#endif // T100LISTCTRL_H
