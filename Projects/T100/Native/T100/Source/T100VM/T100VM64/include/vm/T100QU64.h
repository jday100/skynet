#ifndef T100QU64_H
#define T100QU64_H

#include "T100Common.h"
#include "T100Cpu64.h"
#include "T100Memory64.h"
#include "T100Port64.h"
#include "T100Bus64.h"


class T100QU64
{
    public:
        T100QU64();
        virtual ~T100QU64();

        T100BOOL            start(INT64);

        T100BOOL            stop();

    protected:

    private:
        T100Cpu64*          m_cpu           = T100NULL;
        T100Memory64*       m_memory        = T100NULL;
        T100Port64*         m_port          = T100NULL;
        T100Bus64*          m_bus           = T100NULL;
};

#endif // T100QU64_H
