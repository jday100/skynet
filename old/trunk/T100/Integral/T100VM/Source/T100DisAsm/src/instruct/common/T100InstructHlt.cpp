#include "T100InstructHlt.h"

#include "T100Console.h"

T100InstructHlt::T100InstructHlt() :
    T100Instruct()
{
    //ctor
}

T100InstructHlt::~T100InstructHlt()
{
    //dtor
}

T100BOOL T100InstructHlt::Execute()
{
    return T100FALSE;
}

T100BOOL T100InstructHlt::Parse()
{
    T100Console::Out("Hlt\n");
    return T100TRUE;
}
