#include "T100CPU64Base.h"

#include "T100Host64.h"

T100CPU64Base::T100CPU64Base(T100Host64* host) :
    m_host(host)
{
    //ctor
    m_flag      = T100FALSE;
}

T100CPU64Base::~T100CPU64Base()
{
    //dtor
}

T100BOOL T100CPU64Base::Pulse()
{
    static T100Instruct*    instruct      = T100NULL;
    static T100BYTE         data;

    if(m_flag){
        if(m_host->m_bus.IsBusy()){
            if(instruct){
                instruct->Execute(data);
            }else{
                if(m_host->m_bus.IsReady()){
                    m_host->m_bus.Read(GetAddress(), &data);

                    instruct  = m_instructs[data];

                    if(instruct){
                        instruct->Execute(data);
                        m_flag  = T100TRUE;
                    }else{

                    }
                }
            }
        }else{
            m_host->m_bus.Acquire();

            if(m_host->m_bus.IsReady()){
                m_host->m_bus.Read(GetAddress(), &data);

                instruct  = m_instructs[data];

                if(instruct){
                    instruct->Execute(data);
                    m_flag  = T100TRUE;
                }else{

                }
            }
        }

    }else{
        if(m_host->m_bus.IsBusy()){

        }else{
            m_host->m_bus.Acquire();

            if(m_host->m_bus.IsReady()){
                m_host->m_bus.Read(GetAddress(), &data);

                instruct  = m_instructs[data];

                if(instruct){
                    instruct->Execute(data);
                    m_flag  = T100TRUE;
                }else{

                }
            }else{
                m_flag  = T100TRUE;
            }
        }

    }
}

T100UINT64 T100CPU64Base::GetAddress()
{
    T100UINT32      cs;
    T100UINT32      ip;

    cs  = m_cs.GetValue();
    ip  = m_rip.GetValue();

    return (cs << 4) + ip;
}
