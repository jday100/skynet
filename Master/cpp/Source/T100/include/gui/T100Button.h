#ifndef T100BUTTON_H
#define T100BUTTON_H

#include "gui/control/T100Control.h"
#include "gui/T100ButtonStyle.h"

class T100Button : public T100Control
{
    public:
        T100Button();
        T100Button(T100Window*, T100WSTRING);
        virtual ~T100Button();

        T100VOID            Create(T100Window*, T100WSTRING, T100ButtonStyle* = T100NULL);

    protected:

    private:
};

#endif // T100BUTTON_H
