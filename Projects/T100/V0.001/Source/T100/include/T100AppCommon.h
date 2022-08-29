#ifndef T100APPCOMMON_H
#define T100APPCOMMON_H

#include <wx/cmdline.h>
#include "T100Common.h"

/*
//主程序命令行参数
typedef struct{
    T100BOOL            FLAG;
    T100BOOL            TEST;
    T100BOOL            LIST;
    T100BOOL            HELP;
    T100BOOL            VPC;
    T100BOOL            VDISK;
    T100BOOL            VDM;
    T100BOOL            FONT;
    T100BOOL            IDE;
    T100BOOL            ASSEMBLY;
    T100BOOL            LOG;
    T100BOOL            ERR;
    wxString            INPUT;
    wxString            OUTPUT;
    wxString            FILE;
    wxArrayString       IMPORTS;
    wxString            UNITS;
}T100CMDLINE_STATE;
*/

//命令行参数设定
static const wxCmdLineEntryDesc T100CmdLineDesc[] =
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


#endif // T100APPCOMMON_H
