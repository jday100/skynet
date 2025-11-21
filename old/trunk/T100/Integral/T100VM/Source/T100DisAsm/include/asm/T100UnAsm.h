#ifndef T100UNASM_H
#define T100UNASM_H

#include "T100CmdLine.h"

class T100UnAsm
{
    public:
        T100UnAsm();
        virtual ~T100UnAsm();

        int             Execute(T100CmdLineInfo*);

    protected:

    private:
};

#endif // T100UNASM_H
