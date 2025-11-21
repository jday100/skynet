#ifndef T100FONTFRAME_H
#define T100FONTFRAME_H

#include "gui/T100Frame.h"
#include "T100FontServer.h"

using namespace T100WINDOWS;

class T100FontFrame : public T100Frame
{
    public:
        T100FontFrame();
        virtual ~T100FontFrame();

        virtual T100VOID            Create(T100Win32Application*, T100FrameStyle* = T100NULL);

    protected:
        T100FontServer              m_server;

        T100VOID                    OnMainMenu(T100MenuEvent& event);

        T100VOID                    CloseEvent();
        T100VOID                    OnClose(T100WindowEvent& event);

        T100VOID                    QuitMenu();
        T100VOID                    OnQuit(T100MenuEvent& event);

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100FONTFRAME_H
