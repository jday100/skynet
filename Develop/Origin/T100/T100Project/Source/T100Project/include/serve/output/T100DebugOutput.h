#ifndef T100DEBUGOUTPUT_H
#define T100DEBUGOUTPUT_H

#include "T100Output.h"

class T100DebugOutput : public T100Output
{
    public:
        T100DebugOutput();
        virtual ~T100DebugOutput();

        virtual T100VOID            Debug(const T100WSTRING&);
        virtual T100VOID            Print(const T100WSTRING&);
        virtual T100VOID            Error(const T100WSTRING&);

    protected:

    private:
};

#endif // T100DEBUGOUTPUT_H
