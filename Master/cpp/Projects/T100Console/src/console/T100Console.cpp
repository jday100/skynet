#include "console/T100Console.h"

#include "console/T100AllConsoles.h"

T100Console::T100Console(T100CONSOLE_TYPE type) :
    m_type(type)
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
    switch(m_type){
    case T100CONSOLE_TYPE_LINUX:
        {
            m_consolePtr    = T100NEW T100ConsoleLinux();
        }
        break;
    case T100CONSOLE_TYPE_WINDOWS:
    default:
        {
            m_consolePtr    = T100NEW T100ConsoleWindows();
        }
        break;
    }
}

T100VOID T100Console::uninit()
{
    T100SAFE_DELETE(m_consolePtr);
}

T100VOID T100Console::SetForegroundColour(T100COLOUR_TYPE type)
{
    m_consolePtr->SetForegroundColour(type);
}

T100COLOUR_TYPE T100Console::GetForegroundColour()
{
    return m_consolePtr->GetForegroundColour();
}

T100VOID T100Console::SetBackgroundColour(T100COLOUR_TYPE type)
{
    m_consolePtr->SetBackgroundColour(type);
}

T100COLOUR_TYPE T100Console::GetBackgroundColour()
{
    return m_consolePtr->GetBackgroundColour();
}

T100VOID T100Console::OutLine(T100WSTRING msg)
{
    m_consolePtr->OutLine(msg);
}

T100VOID T100Console::GetLine(T100WSTRING& msg)
{
    m_consolePtr->GetLine(msg);
}
