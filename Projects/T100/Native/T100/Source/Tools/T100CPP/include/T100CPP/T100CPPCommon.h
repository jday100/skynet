#ifndef T100CPPCOMMON_H
#define T100CPPCOMMON_H

#include <wx/cmdline.h>

//命令行参数设定
static const wxCmdLineEntryDesc T100CPPCmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH, "?", "usage",          "run usage" },
    //
    { wxCMD_LINE_SWITCH, "T", "test",           "run test" },
    { wxCMD_LINE_SWITCH, "H", "help",           "show help" },
    { wxCMD_LINE_SWITCH, "V", "vpc",            "run vpc" },
    { wxCMD_LINE_SWITCH, "D", "vdisk",          "run vdisk console" },
    { wxCMD_LINE_SWITCH, "M", "vdm",            "run vdisk manager" },
    { wxCMD_LINE_SWITCH, "F", "font",           "run font file builder" },
    { wxCMD_LINE_SWITCH, "I", "ide",            "run ide" },
    { wxCMD_LINE_SWITCH, "A", "assembly",       "run assembler" },
    { wxCMD_LINE_SWITCH, "L", "log",            "setup log" },
    { wxCMD_LINE_SWITCH, "E", "error",          "setup error" },
    //
    { wxCMD_LINE_SWITCH, "q", "quit",           "quit app" },
    { wxCMD_LINE_SWITCH, "l", "list",           "list test units" },
    { wxCMD_LINE_OPTION, "i", "input",          "input file" },
    { wxCMD_LINE_OPTION, "o", "output",         "output file" },
    { wxCMD_LINE_OPTION, "f", "file",           "input file" },
    { wxCMD_LINE_OPTION, "p", "imports",        "import path" },
    { wxCMD_LINE_OPTION, "u", "unit",           "test unit" },
    { wxCMD_LINE_OPTION, "s", "offset",         "memory offset" },
    //
    { wxCMD_LINE_NONE }
};

#endif // T100CPPCOMMON_H
