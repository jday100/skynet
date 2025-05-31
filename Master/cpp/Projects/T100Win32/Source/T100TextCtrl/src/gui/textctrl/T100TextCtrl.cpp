#include "T100TextCtrl.h"

#include "gui/T100TextBoxStyle.h"

T100TextCtrl::T100TextCtrl() :
    T100Control()
{
    //ctor
}

T100TextCtrl::T100TextCtrl(T100Win32Application* app, T100Window* parent) :
    T100Control()
{
    //ctor
}

T100TextCtrl::~T100TextCtrl()
{
    //dtor
}

T100VOID T100TextCtrl::Create(T100Win32Application* app, T100Window* parent)
{
    T100TextBoxStyle        style;

    T100Control::Create(parent, &style);
}
