#ifndef T100TEXTFILEACCESSOR_H
#define T100TEXTFILEACCESSOR_H

#include "T100FileAccessor.h"

class T100TextFileAccessor : public T100FileAccessor
{
    public:
        T100TextFileAccessor();
        virtual ~T100TextFileAccessor();

        T100BOOL            Read();
        T100BOOL            Write();

        T100DWORD           Seek();

    protected:

    private:
};

#endif // T100TEXTFILEACCESSOR_H
