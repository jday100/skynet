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
        std::string         m_root;

        T100VOID            Execute(std::string);

        std::string         CWD();

    private:
        T100VOID            init();
        T100VOID            uninit();
};

#endif // T100SHELL_H
