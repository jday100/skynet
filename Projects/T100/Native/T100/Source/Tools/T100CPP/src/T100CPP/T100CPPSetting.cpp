#include "T100CPPSetting.h"

T100WString T100CPPSetting::TEST_PATH           = L"test";

T100CPPSetting::T100CPPSetting()
    :T100Setting()
{
    //ctor
}

T100CPPSetting::~T100CPPSetting()
{
    //dtor
}

T100WString T100CPPSetting::GetTest(T100WString path)
{
    T100WString         name;

    name    = TEST_PATH + path;

    return name;
}
