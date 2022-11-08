#ifndef T100CONSOLECOMMON_H
#define T100CONSOLECOMMON_H

#include "T100Class.h"
#include "T100Common.h"
#include "T100GraphicCommon.h"
#include "T100DataStructure.h"


#define     T100CONSOLE_PROMPT_DEFAULT                  L'?'
#define     T100CONSOLE_SEPARATOR_DEFAULT               L' '
#define     T100CONSOLE_COMMAND_PROMPT_DEFAULT          L'-'
#define     T100CONSOLE_COMMAND_EQUAL_DEFAULT           L'='

#define     T100CONSOLE_COMMAND_VECTOR                  T100WSTRING_VECTOR

namespace T100Library{

typedef enum{
    T100CONSOLE_TYPE_NONE           = 0,
    T100CONSOLE_TYPE_WINDOWS,
    T100CONSOLE_TYPE_LINUX,
    T100CONSOLE_TYPE_LOG,
    T100CONSOLE_TYPE_TERMINAL,
    T100CONSOLE_TYPE_MAX
}T100CONSOLE_TYPE;

}

#endif // T100CONSOLECOMMON_H
