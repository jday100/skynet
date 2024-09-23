#ifndef T100CPPBYTESCANNER_H
#define T100CPPBYTESCANNER_H

#include "T100Common.h"
#include "T100WString.h"

class T100CPPByteScanner
{
    public:
        T100CPPByteScanner();
        virtual ~T100CPPByteScanner();

        virtual T100BOOL        open(T100WString);
        virtual T100BOOL        close();

        virtual T100BOOL        next();

    protected:

    private:
};

#endif // T100CPPBYTESCANNER_H
