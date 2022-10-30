#ifndef T100THISAPPCMDLINEPARSER_H
#define T100THISAPPCMDLINEPARSER_H

#include "T100CmdLineParser.h"
#include "T100CmdLineSwitch.h"
#include "T100CmdLineOption.h"
#include "T100CmdLineParam.h"
#include "T100ThisAppCmdLineResult.h"


class T100ThisAppCmdLineParser : public T100Library::T100CmdLineParser
{
    public:
        T100ThisAppCmdLineParser();
        virtual ~T100ThisAppCmdLineParser();

    protected:
        T100BOOL            classify(T100Library::T100CmdLineInfo&, T100Library::T100CmdLineResult&);

        T100BOOL            setSwitch(T100Library::T100CmdLineSwitch&, T100ThisAppCmdLineResult&);
        T100BOOL            setOption(T100Library::T100CmdLineOption&, T100ThisAppCmdLineResult&);
        T100BOOL            setParam(T100Library::T100CmdLineParam&, T100ThisAppCmdLineResult&);

    private:
        T100WORD            m_index         = 0;

};

#endif // T100THISAPPCMDLINEPARSER_H
