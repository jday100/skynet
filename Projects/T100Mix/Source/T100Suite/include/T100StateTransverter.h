#ifndef T100STATETRANSVERTER_H
#define T100STATETRANSVERTER_H

#include "T100Common.h"
#include "base\T100State.h"


class T100StateTransverter
{
    public:
        T100StateTransverter();
        virtual ~T100StateTransverter();

        virtual T100State*          GetCurrent() = 0;
        virtual T100BOOL            Change(T100State*);

    protected:
        T100WORD                    m_current           = 0;

    private:
};

#endif // T100STATETRANSVERTER_H
