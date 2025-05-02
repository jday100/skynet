#ifndef T100WINDOW_H
#define T100WINDOW_H

#include <vector>
#include <windows.h>
#include "base/T100Size.h"
#include "base/T100Point.h"
#include "gui/T100WindowBase.h"

class T100Layout;

#define     T100WINDOW_VECTOR           std::vector<T100Window*>

LRESULT CALLBACK T100DefaultWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Window : public T100WindowBase
{
    public:
        T100Window();
        T100Window(T100Window*, T100WSTRING);
        virtual ~T100Window();

        T100VOID            Create(T100Window*, T100WSTRING, T100UINT, T100UINT);
        T100VOID            Destroy();

        HWND                GetHWND();

        T100VOID            SetLayoutPtr(T100Layout*);
        T100Layout*         GetLayoutPtr();

        T100VOID            AddChildPtr(T100Window*);

        T100VOID            Show();
        T100VOID            Hide();

        T100Size            GetSize();
        T100VOID            SetSize(T100Size);

        T100Size            GetClientSize();
        T100VOID            SetClientSize(T100Size);

        T100VOID            SetPosition(T100Point);
        T100Point           GetPosition();

        T100INT             Run();

    protected:
        //HWND                    m_hwnd;
        //T100UINT                m_width;
        //T100UINT                m_height;

        T100Point               m_position;

        T100Window*             m_parentPtr         = T100NULL;
        T100WINDOW_VECTOR       m_children;

        T100Layout*             m_layoutPtr         = T100NULL;

        T100VOID                OnResize(T100Event&);

    private:

        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100WINDOW_H
