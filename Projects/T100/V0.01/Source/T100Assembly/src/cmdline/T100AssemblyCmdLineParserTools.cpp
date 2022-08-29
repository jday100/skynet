#include "T100AssemblyCmdLineParserTools.h"
#include "T100CmdLineStringScanner.h"
#include "T100CmdLineCharScanner.h"
#include "T100AssemblyCmdLineParameterScanner.h"
#include "T100AssemblyCmdLineParser.h"


T100AssemblyCmdLineParserTools::T100AssemblyCmdLineParserTools()
{
    //ctor
}

T100AssemblyCmdLineParserTools::~T100AssemblyCmdLineParserTools()
{
    //dtor
}

T100BOOL T100AssemblyCmdLineParserTools::parse(int argc, wchar_t** argv, T100AssemblyCmdLineInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100CmdLineStringScanner                    strscanner;
    T100CmdLineCharScanner                      chscanner;
    T100AssemblyCmdLineParameterScanner         parascanner;
    T100AssemblyCmdLineParser                   parser;

    result = parser.parse(argc, argv);
    if(result){

    }

    return result;
}
