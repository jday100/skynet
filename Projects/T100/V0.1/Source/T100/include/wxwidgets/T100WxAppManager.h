#ifndef T100WXAPPMANAGER_H
#define T100WXAPPMANAGER_H

#include <wx/frame.h>
#include "library\\T100AppManager.h"


namespace T100WxWidgets{

class T100WxAppManager : public T100Library::T100AppManager
{
    public:
        T100WxAppManager();
        virtual ~T100WxAppManager();

        wxFrame*            getFrame();

        T100BOOL            quit(T100WORD = 0);

    protected:
        wxFrame*            m_frame         = T100NULL;

    private:
        T100VOID            create();
        T100VOID            destroy();

};

}

#endif // T100WXAPPMANAGER_H
