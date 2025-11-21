#ifndef T100CPU64_H
#define T100CPU64_H

#include "T100CPU64Base.h"
#include "T100Instruct.h"
#include "T100Register64.h"
#include "T100Register128.h"

class T100Host64;

class T100CPU64 : public T100CPU64Base
{
    public:
        T100CPU64(T100Host64*);
        virtual ~T100CPU64();

        T100VOID                    Info(T100DebugFrame*);

    protected:
        T100VOID                    Execute();
        T100VOID                    Parse(T100BYTE);

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100CPU64_H
