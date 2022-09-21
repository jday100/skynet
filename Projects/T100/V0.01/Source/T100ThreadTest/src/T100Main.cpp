#include "T100Main.h"


T100Main::T100Main()
{
    //ctor
}

T100Main::~T100Main()
{
    //dtor
}

T100BOOL T100Main::run()
{
    m_master    = T100NEW T100Master();
    m_slave     = T100NEW T100Slave();

    m_master->setMain(this);
    m_slave->setMain(this);

    m_master->start();
    m_slave->start();
}

T100VOID T100Main::quit()
{
    m_master->stop();
    m_slave->stop();
}
