#include "T100TextBoxStyle.h"

#include "gui/common/T100WindowCommon.h"

T100TextBoxStyle::T100TextBoxStyle() :
    T100WindowStyle()
{
    //ctor
    WindowStyle     = WS_CHILD | WS_VSCROLL | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL;
    ExStyle         = 0;

    WindowLabel     = T100WINDOW_TYPE_T100TEXTCTRL;
    ClassType       = T100WINDOW_TYPE_EDIT;

    Width           = 50;
    Height          = 30;
}

T100TextBoxStyle::~T100TextBoxStyle()
{
    //dtor
}
