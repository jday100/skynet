#ifndef T100INSTRUCTNOP_H
#define T100INSTRUCTNOP_H

#include "T100Instruct.h"

class T100InstructNop : public T100Instruct
{
    public:
        T100InstructNop();
        virtual ~T100InstructNop();

        T100BYTE                    m_byte      = 0x90;

        virtual T100BOOL            Execute();

        virtual T100BOOL            Parse();

    protected:

    private:
};

#endif // T100INSTRUCTNOP_H
