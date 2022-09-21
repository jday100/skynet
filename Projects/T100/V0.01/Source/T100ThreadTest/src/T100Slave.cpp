#include "T100Slave.h"

#include "T100TestTools.h"
#include "T100Main.h"


T100Slave::T100Slave()
{
    //ctor
}

T100Slave::~T100Slave()
{
    //dtor
}

T100VOID T100Slave::setMain(T100Main* value)
{
    m_main = value;
}

T100VOID T100Slave::run()
{
    while(1){
        T100TestTools::Print(L"Slave");

        //m_main->m_flag = !m_main->m_flag;
        m_main->m_flag = true;
        sleep(1000);
    }

}
