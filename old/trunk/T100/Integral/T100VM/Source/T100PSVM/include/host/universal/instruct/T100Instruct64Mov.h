#ifndef T100INSTRUCT64MOV_H
#define T100INSTRUCT64MOV_H

#include <atomic>
#include "T100Instruct64.h"

class T100Instruct64Mov : public T100Instruct64
{
    public:
        T100Instruct64Mov(T100CPU64*);
        virtual ~T100Instruct64Mov();

        T100VOID                    Append(T100INSTRUCT_HASH&);

        virtual T100VOID            Execute(T100BYTE);

    protected:
        std::atomic_uint            m_count;

    private:
};

#endif // T100INSTRUCT64MOV_H
