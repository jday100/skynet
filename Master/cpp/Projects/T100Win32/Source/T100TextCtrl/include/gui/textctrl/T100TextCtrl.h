#ifndef T100TEXTCTRL_H
#define T100TEXTCTRL_H

#include "gui/control/T100Control.h"

class T100Win32Application;

class T100TextCtrl : public T100Control
{
    public:
        T100TextCtrl();
        T100TextCtrl(T100Win32Application*, T100Window*);
        virtual ~T100TextCtrl();

        T100VOID            Create(T100Win32Application*, T100Window*);

    protected:

    private:
};

#endif // T100TEXTCTRL_H
