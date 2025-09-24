#ifndef T100OUTPUT_H
#define T100OUTPUT_H

#include "T100Common.h"

class T100Output
{
    public:
        T100Output();
        virtual ~T100Output();

        virtual T100VOID            Debug(const T100WSTRING&) = 0;
        virtual T100VOID            Print(const T100WSTRING&) = 0;
        virtual T100VOID            Error(const T100WSTRING&) = 0;

    protected:

    private:
};

#endif // T100OUTPUT_H
