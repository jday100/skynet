#include "gui/data/T100WindowMessageData.h"

T100WindowMessageData::T100WindowMessageData(HWND hwnd, UINT id, WPARAM wParam, LPARAM lParam)
{
    //ctor
    WINDOW_HWND     = hwnd;
    MESSAGE_ID      = id;
    WINDOW_WPARAM   = wParam;
    WINDOW_LPARAM   = lParam;
}

T100WindowMessageData::~T100WindowMessageData()
{
    //dtor
}
