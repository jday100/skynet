#ifndef T100TREECTRL_H
#define T100TREECTRL_H

#include "gui/T100Window.h"

class T100TreeCtrl : public T100Window
{
    public:
        T100TreeCtrl();
        virtual ~T100TreeCtrl();

        T100VOID            Append(T100WSTRING);

    protected:

    private:
};

#endif // T100TREECTRL_H
