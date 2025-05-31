#ifndef T100FRAMEBASE_H
#define T100FRAMEBASE_H

#include "gui/base/T100Size.h"
#include "gui/T100MenuBar.h"
#include "gui/window/T100SelfLoopWindow.h"
#include "gui/T100FrameStyle.h"

class T100Win32Application;

class T100FrameBase : public T100SelfLoopWindow
{
    public:
        T100FrameBase();
        T100FrameBase(T100Win32Application*, T100FrameStyle* = T100NULL);
        virtual ~T100FrameBase();

        T100VOID            Create(T100Win32Application*, T100FrameStyle* = T100NULL);

        T100VOID            SetClientSize(T100Size);
        T100Size            GetClientSize();

        T100VOID            SetMenuBar(T100MenuBar*);
        T100MenuBar*        GetMenuBarPtr();

        T100VOID            Maximize();
        T100VOID            Minimize();

    protected:
        T100Size            m_clientSize;
        T100MenuBar*        m_menuBarPtr            = T100NULL;

    private:
};

#endif // T100FRAMEBASE_H
