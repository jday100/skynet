#include "T100ButtonFrame.h"

#include "gui/T100Button.h"
#include "gui/T100FillLayout.h"

T100ButtonFrame::T100ButtonFrame() :
    T100Frame()
{
    //ctor
}

T100ButtonFrame::~T100ButtonFrame()
{
    //dtor
}

T100VOID T100ButtonFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100ButtonFrame::init()
{
    T100FillLayout*     layout  = T100NEW T100FillLayout();

    T100Button*         button1     = T100NEW T100Button(this, L"OK");
    T100Button*         button2     = T100NEW T100Button();

    button2->Create(this, L"OK");

    button1->Show();
    button2->Show();


    //layout->SetOrientationType(T100HORIZONTAL);

    //this->SetLayout(layout);

}

T100VOID T100ButtonFrame::uninit()
{

}
