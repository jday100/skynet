#include "T100MessageBox.h"

T100INT     ShowMessageBox(T100SelfLoopWindow* parent, T100WSTRING msg, T100WSTRING title, T100INT type)
{
    return MessageBox(parent->GetHWND(), msg.c_str(), title.c_str(), type);
}
