#ifndef T100INSTRUCTHLT_H
#define T100INSTRUCTHLT_H

#include "T100Instruct.h"

class T100InstructHlt : public T100Instruct
{
    public:
        T100InstructHlt();
        virtual ~T100InstructHlt();

        T100BYTE                    m_byte      = 0xF4;

        virtual T100BOOL            Execute();
        virtual T100BOOL            Parse();

    protected:

    private:
};

#endif // T100INSTRUCTHLT_H
