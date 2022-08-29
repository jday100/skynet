#ifndef T100EXECUTABLEREALTINYBUILDER_H
#define T100EXECUTABLEREALTINYBUILDER_H

#include "T100CodeBuilder.h"


class T100ExecutableRealTinyBuilder : public T100CodeBuilder
{
    public:
        T100ExecutableRealTinyBuilder();
        virtual ~T100ExecutableRealTinyBuilder();

        T100BOOL            save(T100STDSTRING, T100Code*);

    protected:

    private:
};

#endif // T100EXECUTABLEREALTINYBUILDER_H
