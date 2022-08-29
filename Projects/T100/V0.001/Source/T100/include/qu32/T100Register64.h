#ifndef T100REGISTER64_H
#define T100REGISTER64_H

#include "T100Common.h"


class T100Register64
{
    public:
        T100Register64();
        virtual ~T100Register64();

        T100VOID        setValue(T100DWORD);
        T100DWORD       getValue();

    protected:

    private:
        T100DWORD       m_value             = 0;
};

#endif // T100REGISTER64_H
