#ifndef T100BUTTON_H
#define T100BUTTON_H

#include "gui/T100ButtonStyle.h"
#include "gui/control/T100Control.h"

namespace T100WINDOWS{

class T100Button : public T100Control
{
    public:
        T100Button();
        T100Button(T100Window*, const T100WSTRING&);
        virtual ~T100Button();

        virtual T100VOID            Create(T100Window*, const T100WSTRING&, T100ButtonStyle* = T100NULL);
        virtual T100VOID            Destroy();

    protected:

    private:
        T100VOID                    init(T100Window*, const T100WSTRING&);
        T100VOID                    uninit();
};

}

#endif // T100BUTTON_H
