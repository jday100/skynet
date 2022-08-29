#ifndef T100EXECUTABLENORMALSMALLBUILDER_H
#define T100EXECUTABLENORMALSMALLBUILDER_H

#include "T100CodeBuilder.h"


class T100ExecutableNormalSmallBuilder : public T100CodeBuilder
{
    public:
        T100ExecutableNormalSmallBuilder();
        virtual ~T100ExecutableNormalSmallBuilder();

        T100BOOL            save(T100STDSTRING, T100Code*);

    protected:

    private:
};

#endif // T100EXECUTABLENORMALSMALLBUILDER_H
