#ifndef T100INSTRUCTACTUATOR_H
#define T100INSTRUCTACTUATOR_H

#include <atomic>
#include "T100Instruct.h"

class T100InstructActuator
{
    public:
        T100InstructActuator(T100BYTE_VECTOR&);
        virtual ~T100InstructActuator();

        T100INSTRUCT_HASH           m_instructs;

        T100BOOL                    Create();
        T100BOOL                    Destroy();

        T100INT                     Parse();

    protected:
        T100BYTE_VECTOR&            m_data;


        T100VOID                    ParseInstruct();

    private:
        std::atomic_uint            m_index;

        T100BYTE                    Read();

        T100VOID                    Parse0F();
        T100VOID                    Parse11();
        T100VOID                    Parse20();

        T100VOID                    Parse2C();

        T100VOID                    ParseE9S();

        T100VOID                    ParseA8();
        T100VOID                    ParseE9();

        T100VOID                    ParseFF();
};

#endif // T100INSTRUCTACTUATOR_H
