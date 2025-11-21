#include "T100InstructActuator.h"

#include "T100Console.h"
#include "T100InstructSetIntelI386.h"

T100InstructActuator::T100InstructActuator(T100BYTE_VECTOR& data) :
    m_data(data),
    m_instructs()
{
    //ctor
    m_index     = 0;
}

T100InstructActuator::~T100InstructActuator()
{
    //dtor
}

T100BOOL T100InstructActuator::Create()
{
    T100InstructSetIntelI386        i386(*this);

    i386.Load();
}

T100BOOL T100InstructActuator::Destroy()
{

}

T100BYTE T100InstructActuator::Read()
{
    return m_data.at(m_index++);
}

T100INT T100InstructActuator::Parse()
{
    ParseInstruct();
}

/*
mov     %cr0, %rax      : 0F 20 C0
test    $0x1, %al
je      0xfffffffc
jmp     0xffffff28
.byte   0xe9
adc     %edi, %edi
*/

T100VOID T100InstructActuator::ParseInstruct()
{
    T100Instruct*       instruct        = T100NULL;

    while(m_index < m_data.size()){
        T100BYTE    byte    = Read();

        instruct    = m_instructs[byte];

        if(instruct)
        {
            instruct->Parse();
            continue;
        };

        switch(byte){
        case 0x05:
            {
                ParseE9();
            }
            break;
        case 0x0F:
            {
                Parse0F();
            }
            break;
        case 0x11:
            {
                Parse11();
            }
            break;
        case 0x2C:
            {
                Parse2C();
            }
            break;
        case 0xA8:
            {
                ParseA8();
            }
            break;
        case 0xE9:
            {
                ParseE9S();
            }
            break;
        default:
            break;
        }
    }

}

T100VOID T100InstructActuator::Parse0F()
{
    T100BYTE    byte    = Read();

    switch(byte){
    case 0x20:
        {
            Parse20();
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::Parse11()
{
    T100BYTE    byte    = Read();

    switch(byte){
    case 0xFF:
        {
            ParseFF();
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::Parse20()
{
    T100BYTE    byte    = Read();

    switch(byte){
    case 0xC0:
        {
            T100Console::Out("mov   %cr0, %rax\n");
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::ParseA8()
{
    T100BYTE    byte    = Read();

    byte    = Read();

    switch(byte){
    case 0x74:
        {
            T100Console::Out("test    $0x1, %al\n");
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::ParseE9()
{
    T100BYTE    byte    = Read();

    switch(byte){
    case 0xE9:
        {
            T100Console::Out("je      0xfffffffc\n");
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::Parse2C()
{
    T100BYTE    byte    = Read();

    byte    = Read();

    byte    = Read();

    switch(byte){
    case 0xFF:
        {
            T100Console::Out("jmp     0xffffff28\n");
        }
        break;
    default:
        break;
    }
}

T100VOID T100InstructActuator::ParseE9S()
{
    T100Console::Out(".byte   0xe9\n");
}

T100VOID T100InstructActuator::ParseFF()
{
    T100Console::Out("adc     %edi, %edi\n");
}
