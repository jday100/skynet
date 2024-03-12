#ifndef T100ASM64LINKER_H
#define T100ASM64LINKER_H

#include "T100ParseInfo.h"
#include "T100BuildInfo.h"

class T100Asm64Linker
{
    public:
        T100Asm64Linker();
        virtual ~T100Asm64Linker();

        T100BOOL            run(T100ParseInfo&, T100BuildInfo&);

    protected:

    private:
};

#endif // T100ASM64LINKER_H
