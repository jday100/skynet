#ifndef T100ASSEMBLYCMDLINERESULT_H
#define T100ASSEMBLYCMDLINERESULT_H

#include "T100CmdLineResult.h"
#include "T100DataStructure.h"


class T100AssemblyCmdLineResult : public T100CmdLineResult
{
    public:
        T100AssemblyCmdLineResult();
        virtual ~T100AssemblyCmdLineResult();

        T100BOOL                TEST            = T100FALSE;
        T100BOOL                UNIT            = T100FALSE;
        T100WSTRING             NAME;

        T100WSTRING             SOURCE;
        T100WSTRING             TARGET;

        T100WSTRING_VECTOR      PATHS;

    protected:

    private:
};

#endif // T100ASSEMBLYCMDLINERESULT_H
