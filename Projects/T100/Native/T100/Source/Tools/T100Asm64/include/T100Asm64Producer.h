#ifndef T100ASM64PRODUCER_H
#define T100ASM64PRODUCER_H

#include "T100BuildInfo.h"


class T100Asm64Producer
{
    public:
        T100Asm64Producer();
        virtual ~T100Asm64Producer();

        T100BOOL            run(T100BuildInfo&);

    protected:

    private:
};

#endif // T100ASM64PRODUCER_H
