#include "T100ThisAppSetup.h"

#include <sstream>

T100STRING          T100ThisAppSetup::APP_TEST_PATH                     = L".\\test";
T100STRING          T100ThisAppSetup::m_resources                       = L"resources";
T100STRING          T100ThisAppSetup::m_build                           = L"build";
T100STRING          T100ThisAppSetup::m_stores                          = L"stores";
T100STRING          T100ThisAppSetup::m_work                            = L"work";


T100ThisAppSetup::T100ThisAppSetup()
    :T100Library::T100AppSetup()
{
    //ctor
}

T100ThisAppSetup::~T100ThisAppSetup()
{
    //dtor
}

T100STRING T100ThisAppSetup::getTestResources(T100STRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_resources.to_wstring() << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_resources.to_wstring() << L"\\" << path.to_wstring();
    }
    return result.str();
}
