#ifndef T100SOURCEIMPORTINFO_H
#define T100SOURCEIMPORTINFO_H

#include "T100Common.h"

class T100SourceImportInfo
{
    public:
        T100SourceImportInfo();
        virtual ~T100SourceImportInfo();

        T100WSTRING                 Compiler;
        T100WSTRING                 Source;

    protected:

    private:
};

#endif // T100SOURCEIMPORTINFO_H
