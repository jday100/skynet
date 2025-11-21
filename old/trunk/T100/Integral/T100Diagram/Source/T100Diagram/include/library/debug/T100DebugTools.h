#ifndef T100DEBUGTOOLS_H
#define T100DEBUGTOOLS_H

#include "T100Common.h"

class T100DebugTools
{
    public:
        T100DebugTools();
        virtual ~T100DebugTools();

        static T100VOID             Console(const T100WSTRING&);
        static T100VOID             Print(const T100WSTRING&);
        static T100VOID             Error(const T100WSTRING&);

    protected:

    private:
};

#endif // T100DEBUGTOOLS_H
