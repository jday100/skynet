#ifndef T100PARTDRAWER_H
#define T100PARTDRAWER_H

#include "T100Common.h"


class T100PartDrawer
{
    public:
        T100PartDrawer();
        virtual ~T100PartDrawer();

        T100BOOL            clear();




        T100BOOL            parse(T100String);
        T100BOOL            build(T100String);

        T100BOOL            chdir(T100String);
        T100String          getCwd();

    protected:

    private:
};

#endif // T100PARTDRAWER_H
