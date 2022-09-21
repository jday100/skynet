#ifndef T100SLAVE_H
#define T100SLAVE_H

#include "T100Thread.h"
class T100Main;


class T100Slave : public T100Thread
{
    public:
        T100Slave();
        virtual ~T100Slave();

        T100VOID            setMain(T100Main*);

    protected:
        T100VOID            run();

    private:
        T100Main*           m_main      = T100NULL;

};

#endif // T100SLAVE_H
