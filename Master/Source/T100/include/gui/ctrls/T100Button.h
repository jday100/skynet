#ifndef T100BUTTON_H
#define T100BUTTON_H

#include "gui/ctrls/T100Control.h"

class T100Button : public T100Control
{
    public:
        T100Button();
        T100Button(T100Window*, T100WSTRING);
        virtual ~T100Button();

        T100VOID            Create(T100Window*);

    protected:

    private:
};

#endif // T100BUTTON_H
