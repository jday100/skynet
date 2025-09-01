#ifndef T100SHELL_H
#define T100SHELL_H

#include "T100Common.h"

class T100Shell
{
    public:
        T100Shell();
        virtual ~T100Shell();

        T100VOID            Run(const T100WSTRING&);

        T100VOID            Execute(const T100WSTRING&);

        T100VOID            Print(T100WSTRING&);

    protected:

    private:
};

#endif // T100SHELL_H
