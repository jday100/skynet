#ifndef T100MASTER_H
#define T100MASTER_H

#include "T100Thread.h"
class T100Main;


class T100Master : public T100Thread
{
    public:
        T100Master();
        virtual ~T100Master();

        T100VOID            setMain(T100Main*);

    protected:
        T100VOID            run();

    private:
        T100Main*           m_main      = T100NULL;

};

#endif // T100MASTER_H
