#include "T100Interrupt32.h"

#include "T100Error.h"
#include "T100QU32.h"


T100Interrupt32::T100Interrupt32(T100QU32* host)
    :m_host(host), IInterrupt((IComputer*)host)
{
    //ctor
}

T100Interrupt32::~T100Interrupt32()
{
    //dtor
}

T100VOID T100Interrupt32::interrupt(T100BYTE id)
{
    icall(id);
}

T100VOID T100Interrupt32::call(T100WORD base, T100WORD offset)
{
    push();

    m_host->getCU32()->setCBR(base);
    m_host->getCU32()->setCOR(offset);
}

T100VOID T100Interrupt32::call(T100WORD offset)
{
    push();

    m_host->getCU32()->setCOR(offset);
}

T100VOID T100Interrupt32::ret()
{
    pop();
}

T100VOID T100Interrupt32::icall(T100BYTE id)
{
    if(m_locked)return;
    m_locked = T100TRUE;

    push();

    T100WORD    base, offset;
    T100WORD    root    = 1048576;
    T100WORD    value;

    value   = root + id * 4;

    m_host->getCU32()->setCBR(0);
    base    = m_host->getMemory32()->raw_read(value);
    offset  = m_host->getMemory32()->raw_read(value + 1);

    m_host->getCU32()->setCBR(base);
    m_host->getCU32()->setCOR(offset);

}

T100VOID T100Interrupt32::iret()
{
    pop();
    m_locked = T100FALSE;
}

T100VOID T100Interrupt32::push()
{
    T100WORD_VECTOR* data = T100NEW T100WORD_VECTOR(8);

    (*data)[T100COR] = m_host->getCU32()->getCurrent();
    (*data)[T100CBR] = m_host->getCU32()->getCBR();
    (*data)[T100CCR] = m_host->getCU32()->getCCR();
    (*data)[T100AAR] = m_host->getAU32()->getAAR();
    (*data)[T100ABR] = m_host->getAU32()->getABR();
    (*data)[T100ACR] = m_host->getAU32()->getACR();
    (*data)[T100ADR] = m_host->getAU32()->getADR();

    m_stack.push(data);
}

T100VOID T100Interrupt32::pop()
{
    T100WORD_VECTOR* data = T100NULL;

    data = m_stack.top();
    m_stack.pop();

    m_host->getCU32()->setCOR((*data)[T100COR]);
    m_host->getCU32()->setCBR((*data)[T100CBR]);
    m_host->getCU32()->setCCR((*data)[T100CCR]);
    m_host->getAU32()->setAAR((*data)[T100AAR]);
    m_host->getAU32()->setABR((*data)[T100ABR]);
    m_host->getAU32()->setACR((*data)[T100ACR]);
    m_host->getAU32()->setADR((*data)[T100ADR]);

    data->clear();
    T100DELETE(data);
}

T100VOID T100Interrupt32::lock()
{
    m_locked = T100TRUE;
}

T100VOID T100Interrupt32::unlock()
{
    m_locked = T100FALSE;
}
