#ifndef T100WINDOWMESSAGEDATA_H
#define T100WINDOWMESSAGEDATA_H

#include <windows.h>

class T100WindowMessageData
{
    public:
        T100WindowMessageData(HWND, UINT, WPARAM, LPARAM);
        virtual ~T100WindowMessageData();

        HWND        WINDOW_HWND;
        UINT        MESSAGE_ID;
        WPARAM      WINDOW_WPARAM;
        LPARAM      WINDOW_LPARAM;

    protected:

    private:
};

#endif // T100WINDOWMESSAGEDATA_H
