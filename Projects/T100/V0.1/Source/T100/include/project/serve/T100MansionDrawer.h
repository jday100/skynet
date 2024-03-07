#ifndef T100MANSIONDRAWER_H
#define T100MANSIONDRAWER_H

#include "T100MansionInfo.h"
#include "T100ProjectInfo.h"

namespace T100PROJECT{

class T100MansionDrawer
{
    public:
        T100MansionDrawer();
        virtual ~T100MansionDrawer();

        T100BOOL            load(T100MansionInfo*, T100PROJECT_INFO_VECTOR*);

    protected:

    private:
};

}

#endif // T100MANSIONDRAWER_H
