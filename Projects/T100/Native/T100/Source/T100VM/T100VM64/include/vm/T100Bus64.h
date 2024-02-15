#ifndef T100BUS64_H
#define T100BUS64_H

#include "T100Common.h"


typedef enum{
    T100BUS_SELECT_MEMORY,
    T100BUS_SELECT_PORT,
    T100BUS_SELECT_CPU
}T100BUS_SIGNAL;

class T100Cpu64;
class T100Memory64;
class T100Port64;


class T100Bus64
{
    public:
        T100Bus64();
        virtual ~T100Bus64();

        T100VOID            read(T100BUS_SIGNAL, INT64, INT64&);
        T100VOID            write(T100BUS_SIGNAL, INT64, INT64);

        T100VOID            setCpu(T100Cpu64*);
        T100VOID            setMemory(T100Memory64*);
        T100VOID            setPort(T100Port64*);

    protected:

    private:
        T100Cpu64*          m_cpu           = T100NULL;
        T100Memory64*       m_memory        = T100NULL;
        T100Port64*         m_port          = T100NULL;
};

#endif // T100BUS64_H
