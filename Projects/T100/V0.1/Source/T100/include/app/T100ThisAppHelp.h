#ifndef T100THISAPPHELP_H
#define T100THISAPPHELP_H

#include "T100Help.h"

class T100ThisAppHelp : public T100Library::T100Help
{
    public:
        T100ThisAppHelp();
        virtual ~T100ThisAppHelp();

        T100VOID            show();

    protected:

    private:
};

#endif // T100THISAPPHELP_H
