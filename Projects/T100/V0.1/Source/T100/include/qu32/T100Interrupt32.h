#ifndef T100INTERRUPT32_H
#define T100INTERRUPT32_H

#include <atomic>
#include "T100Common.h"
#include "T100DataStructure.h"


#define     T100INTERRUPT_STACK             std::stack<T100WORD_VECTOR*>

namespace T100QU32{
class T100QU32;


class T100Interrupt32
{
    public:
        T100Interrupt32(T100QU32*);
        virtual ~T100Interrupt32();

        T100VOID                    interrupt(T100BYTE);

        //call
        T100VOID                    call(T100WORD, T100WORD);
        T100VOID                    call(T100WORD);
        T100VOID                    ret();

        //interrupt
        T100VOID                    icall(T100BYTE);
        T100VOID                    iret();

        T100VOID                    lock();
        T100VOID                    unlock();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100QU32*                   getHost();

        T100VOID                    push();
        T100VOID                    pop();

        T100BOOL                    pushAll();
        T100BOOL                    popAll();

        T100BOOL                    getStack(T100WORD);

    private:
        T100QU32*                   m_host          = T100NULL;

        T100INTERRUPT_STACK         m_stack;
        std::atomic_bool            m_locked;

};

}

#endif // T100INTERRUPT32_H
