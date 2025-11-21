#ifndef T100MESSAGEBOX_H
#define T100MESSAGEBOX_H

#include "gui/T100Window.h"

namespace T100WINDOWS{

#define     T100YES                     6
#define     T100NO                      7

T100INT ShowMessageBox(T100Window*, const T100WSTRING&, const T100WSTRING& = L"MessageBox", T100INT = MB_YESNO);

}

#endif // T100MESSAGEBOX_H
