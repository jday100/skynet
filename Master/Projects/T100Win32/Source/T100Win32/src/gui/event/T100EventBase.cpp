#include "T100EventBase.h"

T100EventBase::T100EventBase()
{
    //ctor
}

T100EventBase::T100EventBase(T100MESSAGE_DATA& data)
{
    //ctor
    WINDOW_HWND = data.WINDOW_HWND;
    MessageID   = data.MESSAGE;
    ID          = (UINT)data.WINDOW_WPARAM;
    FLAGS       = LOWORD(data.WINDOW_LPARAM);
}

T100EventBase::~T100EventBase()
{
    //dtor
}
