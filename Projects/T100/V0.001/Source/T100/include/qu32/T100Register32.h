#ifndef T100REGISTER32_H
#define T100REGISTER32_H

#include "T100Common.h"


class T100Register32
{
    public:
        T100Register32();
        virtual ~T100Register32();

        T100VOID        setValue(T100WORD);
        T100WORD        getValue();

    protected:

    private:
        T100WORD        m_value         = 0;
};

#endif // T100REGISTER32_H
