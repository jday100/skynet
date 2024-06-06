#ifndef T100WIN_H
#define T100WIN_H

#include <windows.h>
#include "T100Common.h"

class T100Win
{
    public:
        T100Win();
        virtual ~T100Win();

        T100VOID            Run(HINSTANCE, TCHAR[], int);

    protected:
        T100VOID            Create();
        T100VOID            Destroy();

    private:
};

#endif // T100WIN_H
