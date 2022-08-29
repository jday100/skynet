#include "T100AppSetup.h"

#include <sstream>

T100WSTRING         T100AppSetup::APP_TEST_PATH                 = L".\\test";
T100WSTRING         T100AppSetup::m_resources                   = L"resources";
T100WSTRING         T100AppSetup::m_build                       = L"build";
T100WSTRING         T100AppSetup::m_stores                      = L"stores";
T100WSTRING         T100AppSetup::m_work                        = L"work";
T100WSTRING         T100AppSetup::m_log                         = L"logs";


T100AppSetup::T100AppSetup()
{
    //ctor
}

T100AppSetup::~T100AppSetup()
{
    //dtor
}

T100WSTRING T100AppSetup::getTestResources(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH << L"\\" << m_resources << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH << L"\\" << m_resources << L"\\" << path;
    }
    return result.str();
}

T100WSTRING T100AppSetup::getTestBuild(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH << L"\\" << m_build << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH << L"\\" << m_build << L"\\" << path;
    }
    return result.str();
}

T100WSTRING T100AppSetup::getTestStores(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH << L"\\" << m_stores << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH << L"\\" << m_stores << L"\\" << path;
    }
    return result.str();
}

T100WSTRING T100AppSetup::getWork(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << m_work;
    }else{
        result << m_work << L"\\" << path;
    }
    return result.str();
}

T100WSTRING T100AppSetup::getLog(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << m_log << L"\\" << L"error";
    }else{
        result << m_log << L"\\" << path;
    }
    return result.str();
}
