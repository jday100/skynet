#include "T100FillFrame.h"

#include "gui/T100Button.h"
#include "gui/T100FillLayout.h"

T100FillFrame::T100FillFrame() :
    T100Frame()
{
    //ctor
}

T100FillFrame::~T100FillFrame()
{
    //dtor
}

T100VOID T100FillFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100FillFrame::init()
{
    T100Button*     button1     = T100NEW T100Button();
    T100Button*     button2     = T100NEW T100Button();
    T100Button*     button3     = T100NEW T100Button();

    T100Button*     button      = T100NEW T100Button();

    button1->Create(this, L"button1");
    button2->Create(this, L"button2");
    button3->Create(this, L"button3");
    button->Create(this, L"button");

    button1->Show();
    button2->Show();
    button3->Show();
    button->Show();

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    //layout->SetOrientationType(T100HORIZONTAL);

    this->SetLayout(layout);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnFrameResize);
}

T100VOID T100FillFrame::uninit()
{

}

T100VOID T100FillFrame::OnFrameResize(T100WindowEvent& event)
{
    T100Window::OnWindowResize(event);
}
