#ifndef T100MAIN_H
#define T100MAIN_H

#include <atomic>
#include "T100Common.h"
#include "T100Master.h"
#include "T100Slave.h"


class T100Main
{
    friend class T100Master;
    friend class T100Slave;
    public:
        T100Main();
        virtual ~T100Main();

        T100BOOL        run();

        T100VOID        quit();

    protected:
        std::atomic_bool    m_flag;

    private:
        T100Master*     m_master        = T100NULL;
        T100Slave*      m_slave         = T100NULL;

};

#endif // T100MAIN_H
