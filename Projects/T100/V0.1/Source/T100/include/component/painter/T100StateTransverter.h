#ifndef T100STATETRANSVERTER_H
#define T100STATETRANSVERTER_H

#include "T100Common.h"
#include "T100State.h"

namespace T100Component{

class T100StateTransverter
{
    public:
        T100StateTransverter();
        virtual ~T100StateTransverter();

        virtual T100State*      GetCurrent();
        virtual T100BOOL        Change(T100State*);

    protected:

    private:
        T100State*              m_current           = T100NULL;

};

}

#endif // T100STATETRANSVERTER_H
