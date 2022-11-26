#include "T100VPCServe.h"

#include "T100VPCLink.h"


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

    if(!createCallback()){
        return T100FALSE;
    }

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

T100BOOL T100VPCServe::createCallback()
{
    if(!m_callback){
        m_callback = T100NEW T100VPCLink();
    }

    if(m_host){
        m_host->setCallback(m_callback);
        return T100TRUE;
    }
    return T100FALSE;
}

T100WORD T100VPCServe::getReturn()
{
    if(m_host){
        m_return = m_host->getReturn();
    }
    return m_return;
}

}
