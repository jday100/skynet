#include "T100VPCServe.h"

namespace T100VPC{

T100VPCServe::T100VPCServe()
{
    //ctor
}

T100VPCServe::~T100VPCServe()
{
    //dtor
}

T100BOOL T100VPCServe::start()
{
    if(m_host){
        return T100FALSE;
    }

    m_host = T100NEW T100QU32::T100QU32();

    if(!m_host->create()){
        return T100FALSE;
    }

    return m_host->start();
}

T100BOOL T100VPCServe::stop()
{
    if(m_host){

    }
    return T100FALSE;
}

T100BOOL T100VPCServe::running()
{
    if(m_host){
        return m_host->running();
    }
    return T100FALSE;
}

}
