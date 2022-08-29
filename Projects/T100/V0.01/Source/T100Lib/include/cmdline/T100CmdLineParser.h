#ifndef T100CMDLINEPARSER_H
#define T100CMDLINEPARSER_H

#include "T100CmdLineCommon.h"
#include "T100CmdLineStringScanner.h"
#include "T100CmdLineCharScanner.h"
#include "T100CmdLineInfo.h"
#include "T100CmdLineResult.h"


class T100CmdLineParser
{
    public:
        T100CmdLineParser();
        virtual ~T100CmdLineParser();

        virtual T100BOOL            parse(int, wchar_t**, T100CmdLineResult&);

    protected:
        virtual T100BOOL            parse(T100CmdLineCharScanner&, T100CmdLineResult&);
        virtual T100BOOL            classify(T100CmdLineInfo&, T100CmdLineResult&);

    private:
};

#endif // T100CMDLINEPARSER_H
