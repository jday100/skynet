#include "T100WindowMessageData.h"

namespace T100WINDOWS{

T100WindowMessageData::T100WindowMessageData() :
    T100Class(),
    WINDOW_HWND(0),
    MESSAGE_ID(0),
    WINDOW_WPARAM(0),
    WINDOW_LPARAM(0)
{
    //ctor
}

T100WindowMessageData::T100WindowMessageData(HWND hwnd, UINT id, WPARAM wParam, LPARAM lParam) :
    T100Class(),
    WINDOW_HWND(hwnd),
    MESSAGE_ID(id),
    WINDOW_WPARAM(wParam),
    WINDOW_LPARAM(lParam)
{
    //ctor
}

T100WindowMessageData::~T100WindowMessageData()
{
    //dtor
}

}
