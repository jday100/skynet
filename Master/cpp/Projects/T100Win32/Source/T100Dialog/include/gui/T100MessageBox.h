#ifndef T100MESSAGEBOX_H
#define T100MESSAGEBOX_H

#include "gui/window/T100Window.h"

#define     T100YES         6
#define     T100NO          7

T100INT     ShowMessageBox(T100Window*, T100WSTRING, T100WSTRING = L"MessageBox", T100INT = MB_YESNO);

#endif // T100MESSAGEBOX_H
