#ifndef T100IDESERVEBASE_H
#define T100IDESERVEBASE_H

#include "T100Common.h"
class T100IDEServe;


class T100IDEServeBase
{
    public:
        T100IDEServeBase(T100IDEServe*);
        virtual ~T100IDEServeBase();

    protected:
        T100IDEServe*           m_serve         = T100NULL;

    private:

};

#endif // T100IDESERVEBASE_H
