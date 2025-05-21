#ifndef T100WINDOW_H
#define T100WINDOW_H

#include <vector>
#include "gui/window/T100WindowBase.h"
#include "gui/T100AllEvents.h"

#define     T100OBJECT_TREE_VECTOR          std::vector<T100ObjectTreeNode*>

LRESULT CALLBACK DefaultWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100Window : public T100WindowBase
{
    public:
        T100Window();
        T100Window(T100Win32Application*, T100Window*);
        virtual ~T100Window();

        T100VOID                    Create(T100WindowStyle* = T100NULL);
        T100VOID                    Create(T100Win32Application*, T100Window*, T100WindowStyle* = T100NULL);

        T100Window*                 GetParentPtr();

        T100VOID                    SetLayout(T100Layout*);
        T100Layout*                 GetLayoutPtr();

        static T100Window*          ConvertToWindow(T100ObjectTreeNode*);

    protected:
        T100Layout*                 m_layoutPtr     = T100NULL;

        T100VOID                    OnWindowResize(T100WindowEvent&);

    private:
};

#endif // T100WINDOW_H
