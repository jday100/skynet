#ifndef T100PORT_H
#define T100PORT_H

#include <cstring>
#include <windows.h>
#include <winhvplatform.h>
#include "T100VPCFrame.h"

using namespace T100LIBRARY;

class T100Port
{
    public:
        T100Port();
        virtual ~T100Port();

        virtual T100VOID            Run(WHV_RUN_VP_EXIT_CONTEXT&, T100VPCFrame*);

    protected:

    private:
};

#endif // T100PORT_H
