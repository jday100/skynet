#ifndef T100EXECUTABLENORMALBIGBUILDER_H
#define T100EXECUTABLENORMALBIGBUILDER_H

#include "T100CodeBuilder.h"


class T100ExecutableNormalBigBuilder : public T100CodeBuilder
{
    public:
        T100ExecutableNormalBigBuilder();
        virtual ~T100ExecutableNormalBigBuilder();

        T100BOOL            save(T100STDSTRING, T100Code*);

    protected:

    private:
};

#endif // T100EXECUTABLENORMALBIGBUILDER_H
