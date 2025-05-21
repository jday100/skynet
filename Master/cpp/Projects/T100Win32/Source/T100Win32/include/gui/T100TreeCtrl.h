#ifndef T100TREECTRL_H
#define T100TREECTRL_H

#include "T100Window.h"

typedef enum T100EVENT_TREECTRL_TYPE{
    T100EVENT_TREECTRL_SELECTED         = T100EVENT_MAX + 100
}T100EVENT_TREECTRL_TYPE;

LRESULT CALLBACK DefaultTreeCtrlWindowProcedure (HWND, UINT, WPARAM, LPARAM);

class T100TreeCtrl : public T100Window
{
    public:
        T100TreeCtrl();
        T100TreeCtrl(T100Win32Application*, T100Window*);
        virtual ~T100TreeCtrl();

        T100VOID            Create(T100Win32Application*, T100Window*);

        T100VOID            Append(T100WSTRING);

    protected:

    private:
};

#endif // T100TREECTRL_H
