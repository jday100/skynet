#include "T100Win32Capture.h"

int main()
{
    T100Win32Capture        capture;

    HWND    hwnd  = capture.Find(L"Calculator");
}
