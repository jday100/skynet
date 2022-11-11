#include "T100Assembly.h"

#include "T100Produce.h"

namespace T100Assembly{

T100Assembly::T100Assembly(T100Library::T100AppManager* obj)
    :T100Library::T100App(obj)
{
    //ctor
}

T100Assembly::~T100Assembly()
{
    //dtor
}

T100BOOL T100Assembly::run(T100ThisAppCmdLineResult& info)
{
    T100BOOL        result;
    T100STRING      source;
    T100STRING      target;
    T100Produce     produce;

    source = info.SOURCE;
    target = info.TARGET;

    for(T100WSTRING item : info.PATHS){
        T100STRING  temp(item);
        produce.getPathDrawer().append(temp);
    }

    result = produce.run(source, target);

    return result;
}

}
