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

T100VOID T100WindowFrame::Create(T100Win32Application* application)
{
    T100Frame::Create(application);

    /*
    T100SelfLoopWindow*     window      = T100NEW T100SelfLoopWindow(application);

    window->Show();

    T100Panel*      panel       = T100NEW T100Panel();

    panel->Create(this);
    panel->Show();

    T100Window*     w1          = T100NEW T100Window(this);

    //w1->Create();
    w1->Show();

    //SetSize(800, 600);
    */

    Show();
    SetSize(800, 600);
}
