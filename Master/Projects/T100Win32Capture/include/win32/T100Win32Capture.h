#ifndef T100WIN32CAPTURE_H
#define T100WIN32CAPTURE_H

#include <windows.h>
#include "base/T100Class.h"

class T100Win32Capture : public T100Class
{
    public:
        T100Win32Capture();
        virtual ~T100Win32Capture();

        HWND                Find(T100WSTRING);

        T100VOID            Launch(T100WSTRING);

    protected:

    private:
};

#endif // T100WIN32CAPTURE_H
