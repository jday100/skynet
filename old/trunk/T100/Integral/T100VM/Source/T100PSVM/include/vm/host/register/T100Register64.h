#ifndef T100REGISTER64_H
#define T100REGISTER64_H

#include <atomic>
#include "T100Common.h"

class T100Register64
{
    public:
        T100Register64();
        virtual ~T100Register64();

        virtual T100VOID            SetValue(T100UINT64);
        virtual T100UINT64          GetValue();

    protected:
        std::atomic_int64_t         m_value;

    private:
};

#endif // T100REGISTER64_H
