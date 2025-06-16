#ifndef T100WINDOW_H
#define T100WINDOW_H

#include "gui/window/T100WindowBase.h"

namespace T100WINDOWS{

class T100Window : public T100WindowBase
{
    public:
        T100Window();
        T100Window(T100Window*);
        virtual ~T100Window();

        virtual T100VOID            Create(T100Window*, T100WindowStyle* = T100NULL);
        virtual T100VOID            Destroy();

        static T100Window*          ConvertToWindow(T100Tree*);

    protected:

    private:
        T100WindowModule            m_module;

        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100WINDOW_H
