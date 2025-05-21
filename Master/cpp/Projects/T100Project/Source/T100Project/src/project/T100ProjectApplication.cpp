#include "T100ProjectApplication.h"

T100ProjectApplication::T100ProjectApplication() :
    T100PluginApplication()
{
    //ctor
}

T100ProjectApplication::~T100ProjectApplication()
{
    //dtor
}

T100VOID T100ProjectApplication::Create()
{
    T100PluginApplication::Create();
}

T100VOID T100ProjectApplication::Destroy()
{
    T100PluginApplication::Destroy();
}
