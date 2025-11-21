#ifndef T100WINDOW_H
#define T100WINDOW_H

#include "gui/layout/T100Layout.h"
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

        T100VOID                    SetLayout(T100Layout*);
        T100Layout*                 GetLayout();

        static T100Window*          ConvertToWindow(T100Tree*);

    protected:
        T100Layout*                 m_layout        = T100NULL;

        T100VOID                    OnWindowResize(T100WindowEvent&);

    private:
        T100WindowModule            m_module;

        T100VOID                    init(T100Window*);
        T100VOID                    uninit();
};

}

#endif // T100WINDOW_H
