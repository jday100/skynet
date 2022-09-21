#ifndef T100REGISTER32_H
#define T100REGISTER32_H

#include <atomic>
#include "T100Common.h"


class T100Register32
{
    public:
        T100Register32();
        virtual ~T100Register32();

        T100VOID            setValue(T100WORD);
        T100WORD            getValue();

    protected:

    private:
        //volatile T100WORD            m_value         = 0;
        std::atomic_int32_t     m_value;
};

#endif // T100REGISTER32_H
