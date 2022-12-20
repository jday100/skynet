#ifndef T100WXAPP_H
#define T100WXAPP_H

#include <wx/frame.h>
#include "T100AppBase.h"

namespace T100WxWidgets{
class T100WxAppManager;

typedef     T100BOOL (wxFrame::*T100FRAME_CALLBACK)(void*);

class T100WxApp : public T100Library::T100AppBase
{
    public:
        T100WxApp(T100WxAppManager*, T100BOOL = T100FALSE);
        virtual ~T100WxApp();

    protected:

    private:
};

}

#endif // T100WXAPP_H
