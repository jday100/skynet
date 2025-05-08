#ifndef T100WIN32APPLICATION_H
#define T100WIN32APPLICATION_H

#include "gui/T100Frame.h"
#include "T100Application.h"

class T100Win32Application : public T100Application
{
    public:
        T100Win32Application(HINSTANCE, HINSTANCE, LPSTR, T100INT);
        virtual ~T100Win32Application();

        T100VOID                Create(T100WSTRING = L"");
        T100VOID                Destroy();

        T100VOID                SetFramePtr(T100Frame*);
        T100Frame*              GetFramePtr();

        static HINSTANCE        m_thisInstance;
        static T100INT          m_cmdShow;

        T100INT                 Run();

    protected:
        T100Frame*              m_framePtr          = T100NULL;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100WIN32APPLICATION_H
