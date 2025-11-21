#include "console/T100Console.h"

#include "console/T100ConsoleNormal.h"

namespace T100LIBRARY{

T100Console::T100Console() :
    T100Class()
{
    //ctor
    init();
}

T100Console::~T100Console()
{
    //dtor
    uninit();
}

T100VOID T100Console::init()
{
    m_console   = T100NEW T100ConsoleNormal();
}

T100VOID T100Console::uninit()
{
    T100SAFE_DELETE(m_console)
}

T100VOID T100Console::OutLine(const T100WSTRING& value)
{
    m_console->OutLine(value);
}

T100VOID T100Console::GetLine(const T100WSTRING& value)
{
    m_console->GetLine(value);
}

}
