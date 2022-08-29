#ifndef T100ASSEMBLYCMDLINEPARSER_H
#define T100ASSEMBLYCMDLINEPARSER_H

#include "T100CmdLineParser.h"
#include "T100AssemblyCmdLineInfo.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"
#include "T100AssemblyCmdLineResult.h"


class T100AssemblyCmdLineParser : public T100CmdLineParser
{
    public:
        T100AssemblyCmdLineParser();
        virtual ~T100AssemblyCmdLineParser();

    protected:
        T100BOOL            classify(T100CmdLineInfo&, T100CmdLineResult&);

        T100BOOL            setSwitch(T100CmdLineSwitch&, T100AssemblyCmdLineResult&);
        T100BOOL            setOption(T100CmdLineOption&, T100AssemblyCmdLineResult&);
        T100BOOL            setParam(T100CmdLineParam&, T100AssemblyCmdLineResult&);

    private:
        T100WORD            m_index         = 0;

};

#endif // T100ASSEMBLYCMDLINEPARSER_H
