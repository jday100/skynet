#include "T100WindowFrame.h"

#include "gui/T100Panel.h"

T100WindowFrame::T100WindowFrame() :
    T100Frame()
{
    //ctor
}

T100WindowFrame::~T100WindowFrame()
{
    //dtor
}

T100VOID T100WindowFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    T100SelfLoopWindow*     window      = T100NEW T100SelfLoopWindow(GetApplicationPtr(), this);

    window->Create(GetApplicationPtr(), this);
    window->Show();

    T100Panel*      panel       = T100NEW T100Panel();

    panel->Create(this);
    panel->Show();

    T100Window*     w1          = T100NEW T100Window(GetApplicationPtr(), this);

    //w1->Create();
    w1->Show();
}
