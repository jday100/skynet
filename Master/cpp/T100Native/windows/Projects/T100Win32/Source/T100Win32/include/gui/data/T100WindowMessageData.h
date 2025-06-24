#ifndef T100WINDOWMESSAGEDATA_H
#define T100WINDOWMESSAGEDATA_H

#include <windows.h>
#include "base/T100Class.h"

using namespace T100LIBRARY;

namespace T100WINDOWS{

class T100WindowMessageData : public T100Class
{
    public:
        T100WindowMessageData();
        T100WindowMessageData(HWND, UINT, WPARAM, LPARAM);
        virtual ~T100WindowMessageData();

        HWND            WINDOW_HWND;
        UINT            MESSAGE_ID;
        WPARAM          WINDOW_WPARAM;
        LPARAM          WINDOW_LPARAM;

    protected:

    private:
};

}

#endif // T100WINDOWMESSAGEDATA_H
