#ifndef T100WINDOWMODULE_H
#define T100WINDOWMODULE_H

#include <windows.h>
#include "base/T100Class.h"
#include "gui/style/T100WindowStyle.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100EventHandler;
class T100Win32Application;

class T100WindowModule : public T100Class
{
    public:
        T100WindowModule();
        virtual ~T100WindowModule();

        T100BOOL            RegisterWindowClass(HINSTANCE, const T100WindowStyle&);
        HWND                CreateWindowInstance(HINSTANCE, HWND, const T100WindowStyle&, T100VOID* = T100NULL);
        HWND                CreateWindowHandler(T100Win32Application*, HINSTANCE, HWND, T100WindowStyle*, T100EventHandler*, T100VOID*);

    protected:

    private:
};

}

#endif // T100WINDOWMODULE_H
