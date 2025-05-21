#ifndef T100WINDOW_H
#define T100WINDOW_H

#include "gui/window/T100WindowBase.h"
#include "gui/window/T100WindowStyle.h"
#include "gui/T100AllEvents.h"

class T100Layout;
class T100ApplicationEventHandler;

class T100Window : public T100WindowBase
{
    public:
        T100Window();
        T100Window(T100ApplicationEventHandler*, T100Window*, T100WindowStyle* = T100NULL);
        virtual ~T100Window();

        virtual T100VOID            Create(T100ApplicationEventHandler*, T100Window*, T100WindowStyle* = T100NULL);

        T100VOID                    SetLayout(T100Layout*);
        T100Layout*                 GetLayoutPtr();

        static T100Window*          ConvertToWindow(T100ObjectTreeNode*);

    protected:
        T100WindowStyle             m_style;
        T100Layout*                 m_layoutPtr         = T100NULL;

        T100VOID                    OnWindowResize(T100WindowEvent&);

        T100BOOL                    RegisterWindowClass(HINSTANCE, T100WindowStyle*);
        HWND                        CreateWindowInstance(HINSTANCE, HWND, T100WindowStyle*, T100VOID* = T100NULL);

    private:
        T100VOID                    Init(T100ApplicationEventHandler*, T100Window*, T100WindowStyle*);
        T100VOID                    CreateWindowHandler(HINSTANCE, HWND, T100VOID* = T100NULL);
};

#endif // T100WINDOW_H
