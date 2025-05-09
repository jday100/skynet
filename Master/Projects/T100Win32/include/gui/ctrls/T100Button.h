#ifndef T100BUTTON_H
#define T100BUTTON_H

#include "T100Window.h"

class T100Button : public T100Window
{
    public:
        T100Button();
        virtual ~T100Button();

        T100VOID            Create(HWND);

    protected:

    private:
};

#endif // T100BUTTON_H
