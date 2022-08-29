#ifndef T100ASSEMBLYNEW_H
#define T100ASSEMBLYNEW_H

#include "T100AsmCommon.h"
#include "T100Console.h"


class T100Assembly
{
    public:
        T100Assembly();
        virtual ~T100Assembly();

        T100BOOL                run(T100STDSTRING, T100STDSTRING);
        T100BOOL                run(T100STDSTRING);

        T100BOOL                add(T100STDSTRING);

        T100VOID                help();

    protected:
        T100VOID                create();
        T100VOID                destroy();

        static T100Console      m_console;

    private:
        T100STDSTRING_VECTOR    m_imports;

};

#endif // T100ASSEMBLYNEW_H
