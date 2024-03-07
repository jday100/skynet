#ifndef T100PROJECTDRAWER_H
#define T100PROJECTDRAWER_H

#include "T100ProjectInfo.h"

namespace T100PROJECT{

class T100ProjectDrawer
{
    public:
        T100ProjectDrawer();
        virtual ~T100ProjectDrawer();

        T100BOOL            Create(T100ProjectInfo*);

    protected:

    private:
};

}

#endif // T100PROJECTDRAWER_H
