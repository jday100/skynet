#ifndef T100SHELL_H
#define T100SHELL_H

#include "T100Common.h"

using namespace T100LIBRARY;

class T100Shell
{
    public:
        T100Shell();
        virtual ~T100Shell();

        T100INT             Run();

    protected:
        T100VOID            Execute(std::string);

        std::string         CWD();

    private:
};

#endif // T100SHELL_H
