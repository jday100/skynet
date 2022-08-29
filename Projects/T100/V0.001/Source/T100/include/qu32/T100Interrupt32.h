#ifndef T100INTERRUPT32_H
#define T100INTERRUPT32_H

#include <stack>
#include "T100DataTypes.h"
#include "IInterrupt.h"
class T100QU32;


#define     T100INTERRUPT_STACK     std::stack<T100WORD_VECTOR*>


class T100Interrupt32 : public IInterrupt
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
        T100VOID                    push();
        T100VOID                    pop();

    private:
        T100INTERRUPT_STACK         m_stack;
        T100QU32*                   m_host              = T100NULL;

        T100BOOL                    m_locked            = T100FALSE;
};

#endif // T100INTERRUPT32_H
