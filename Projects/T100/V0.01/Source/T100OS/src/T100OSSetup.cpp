#include "T100OSSetup.h"
#include "T100String.h"


T100String      T100OSSetup::m_os_path          = L"os";

T100OSSetup::T100OSSetup()
{
    //ctor
}

T100OSSetup::~T100OSSetup()
{
    //dtor
}

T100String T100OSSetup::getTestOS(T100WSTRING file)
{
    T100String      result;

    result = T100String(APP_TEST_PATH) + L"\\" + m_os_path + L"\\" + file;

    return result;
}
