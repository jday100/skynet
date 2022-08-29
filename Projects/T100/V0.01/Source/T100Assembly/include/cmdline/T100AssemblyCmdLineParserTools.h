#ifndef T100ASSEMBLYCMDLINEPARSERTOOLS_H
#define T100ASSEMBLYCMDLINEPARSERTOOLS_H

#include "T100AssemblyCmdLineInfo.h"


class T100AssemblyCmdLineParserTools
{
    public:
        T100AssemblyCmdLineParserTools();
        virtual ~T100AssemblyCmdLineParserTools();

        static T100BOOL         parse(int, wchar_t**, T100AssemblyCmdLineInfo&);

    protected:

    private:
};

#endif // T100ASSEMBLYCMDLINEPARSERTOOLS_H
