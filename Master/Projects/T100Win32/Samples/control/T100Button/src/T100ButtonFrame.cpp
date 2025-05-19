#include "T100ButtonFrame.h"

#include "gui/T100Button.h"
#include "gui/T100FillLayout.h"

T100ButtonFrame::T100ButtonFrame(T100Win32Application* app) :
    T100Frame(app)
{
    //ctor
}

T100ButtonFrame::~T100ButtonFrame()
{
    //dtor
}

T100VOID T100ButtonFrame::Create(T100WSTRING label)
{
    T100Frame::Create(label);

    init();
}

T100VOID T100ButtonFrame::init()
{
    T100Button*         button  = T100NEW T100Button();
    T100FillLayout*     layout  = T100NEW T100FillLayout();

    button->Create(GetApplicationPtr(), this, L"OK");
    button->Show();

    //layout->SetOrientationType(T100HORIZONTAL);

    //this->SetLayout(layout);

}

T100VOID T100ButtonFrame::uninit()
{

}
