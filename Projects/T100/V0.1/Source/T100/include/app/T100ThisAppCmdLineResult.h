#ifndef T100THISAPPCMDLINERESULT_H
#define T100THISAPPCMDLINERESULT_H

#include "T100DataStructure.h"
#include "T100CmdLineResult.h"


class T100ThisAppCmdLineResult : public T100Library::T100CmdLineResult
{
    public:
        T100ThisAppCmdLineResult();
        virtual ~T100ThisAppCmdLineResult();

        T100BOOL                TEST            = T100FALSE;
        T100BOOL                UNIT            = T100FALSE;
        T100WSTRING             NAME;

        T100WSTRING             SOURCE;
        T100WSTRING             TARGET;

        T100WSTRING_VECTOR      PATHS;

    protected:

    private:
};

#endif // T100THISAPPCMDLINERESULT_H
