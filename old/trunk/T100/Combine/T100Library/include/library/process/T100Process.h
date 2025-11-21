#ifndef T100PROCESS_H
#define T100PROCESS_H

#include "T100Common.h"

class T100Process
{
    public:
        T100Process();
        virtual ~T100Process();

        static T100BOOL             Run(T100STRING);

    protected:

    private:
};

#endif // T100PROCESS_H
