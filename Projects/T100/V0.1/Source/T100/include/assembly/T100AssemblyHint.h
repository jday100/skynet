#ifndef T100ASSEMBLYHINT_H
#define T100ASSEMBLYHINT_H

#include "T100Hint.h"

namespace T100Assembly{
class T100ByteToken;

static T100WSTRING      T100BYTESCAN_BYTE_READ_SUCCESS                      =   L"read success!";
static T100WSTRING      T100BYTESCAN_BYTE_READ_FAILURE                      =   L"read failure!";
static T100WSTRING      T100BYTESCAN_BYTE_CLASSIFY_FINISHED                 =   L"classify finished!";

class T100AssemblyHint : public T100Library::T100Hint
{
    public:
        T100AssemblyHint();
        virtual ~T100AssemblyHint();

        static T100WSTRING      byte_hint(T100ByteToken*, T100WSTRING&);

    protected:

    private:
};

}

#endif // T100ASSEMBLYHINT_H
