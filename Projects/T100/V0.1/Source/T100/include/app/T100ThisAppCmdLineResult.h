#ifndef T100THISAPPCMDLINERESULT_H
#define T100THISAPPCMDLINERESULT_H

#include "T100DataStructure.h"
#include "T100CmdLineResult.h"


class T100ThisAppCmdLineResult : public T100Library::T100CmdLineResult
{
    public:
        T100ThisAppCmdLineResult();
        virtual ~T100ThisAppCmdLineResult();

        T100BOOL                RUNNING         = T100FALSE;

        T100BOOL                TEST            = T100FALSE;
        T100BOOL                HELP            = T100FALSE;

        T100BOOL                ASSEMBLY        = T100FALSE;
        T100BOOL                EDITOR          = T100FALSE;
        T100BOOL                IDE             = T100FALSE;
        T100BOOL                FONT            = T100FALSE;
        T100BOOL                VDISK           = T100FALSE;
        T100BOOL                VDM             = T100FALSE;
        T100BOOL                VPC             = T100FALSE;

        T100BOOL                QUIT            = T100FALSE;
        T100BOOL                LIST            = T100FALSE;

        T100BOOL                LOG             = T100FALSE;
        T100BOOL                ERR             = T100FALSE;

        T100BOOL                UNIT            = T100FALSE;
        T100WSTRING             NAME;

        T100WSTRING             SOURCE;
        T100WSTRING             TARGET;

        T100WSTRING             INPUT;
        T100WSTRING             OUTPUT;
        T100WSTRING             FILE;
        T100WSTRING             OFFSET;

        T100WSTRING_VECTOR      PATHS;

    protected:

    private:
};

#endif // T100THISAPPCMDLINERESULT_H
