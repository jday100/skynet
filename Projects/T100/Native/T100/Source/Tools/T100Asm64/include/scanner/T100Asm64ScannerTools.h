#ifndef T100ASM64SCANNERTOOLS_H
#define T100ASM64SCANNERTOOLS_H

#include "T100Asm64SourceScanner.h"


class T100Asm64ScannerTools
{
    public:
        T100Asm64ScannerTools();
        virtual ~T100Asm64ScannerTools();

        static T100BOOL             build(T100STRING, T100Asm64SourceScanner*&);

    protected:

    private:
};

#endif // T100ASM64SCANNERTOOLS_H
