#ifndef T100ASSEMBLYTESTHINT_H
#define T100ASSEMBLYTESTHINT_H

#include "T100Hint.h"

namespace T100Assembly{

static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_START                      = L"Assembly byte scanner test is starting ... ";
static T100WSTRING          T100TEST_HINT_ASSEMBLY_SCANNER_BYTE_TEST_STOP                       = L"Assembly byte scanner test is stopped . ";


class T100AssemblyTestHint : public T100Library::T100Hint
{
    public:
        T100AssemblyTestHint();
        virtual ~T100AssemblyTestHint();

    protected:

    private:
};

}

#endif // T100ASSEMBLYTESTHINT_H
