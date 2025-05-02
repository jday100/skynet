#include "T100MessageBox.h"

T100INT     ShowMessageBox(T100Window* parent, T100WSTRING msg, T100WSTRING title, T100INT type)
{
    return MessageBox(parent->GetHWND(), msg.c_str(), title.c_str(), type);
}

T100MessageBox::T100MessageBox(T100Window* parent, T100WSTRING msg)
{
    //ctor

}

T100MessageBox::~T100MessageBox()
{
    //dtor
}
