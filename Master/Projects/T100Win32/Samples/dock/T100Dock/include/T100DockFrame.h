#ifndef T100DOCKFRAME_H
#define T100DOCKFRAME_H

#include "gui/T100Frame.h"
#include "gui/T100DockManager.h"

class T100DockFrame : public T100Frame
{
    public:
        T100DockFrame(T100Win32Application*);
        virtual ~T100DockFrame();

        T100VOID            Create(T100WSTRING, T100FrameStyle* = T100NULL);

    protected:
        T100VOID            Init();

        T100VOID            OnResize(T100WindowEvent&);

    private:
        T100DockManager     m_dockManager;
};

#endif // T100DOCKFRAME_H
