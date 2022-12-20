#include "T100AssemblyApp.h"

#include "T100Assembly.h"

namespace T100Assembly{

T100AssemblyApp::T100AssemblyApp(T100Library::T100AppManager* obj)
    :T100Library::T100AppBase(obj)
{
    //ctor
}

T100AssemblyApp::~T100AssemblyApp()
{
    //dtor
}

T100BOOL T100AssemblyApp::run(T100ThisAppCmdLineResult& info)
{
    T100BOOL        result;
    T100STRING      source;
    T100STRING      target;
    T100Assembly    assembly;

    source = info.SOURCE;
    target = info.TARGET;

    for(T100WSTRING item : info.PATHS){
        T100STRING  temp(item);
        assembly.getProduce().getClassPathDrawer().append(temp);
    }

    result = assembly.run(source, target);

    if(m_quit){
        quit();
    }

    return result;
}

}
