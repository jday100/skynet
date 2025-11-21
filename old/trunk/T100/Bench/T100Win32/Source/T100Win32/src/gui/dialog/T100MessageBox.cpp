#include "gui/T100MessageBox.h"

namespace T100WINDOWS{

T100INT ShowMessageBox(T100Window* parent, const T100WSTRING& value, const T100WSTRING& title, T100INT type)
{
    return MessageBox(parent->GetHWND(), value.c_str(), title.c_str(), type);
}

}
