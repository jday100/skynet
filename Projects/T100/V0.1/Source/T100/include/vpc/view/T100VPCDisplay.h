#ifndef T100VPCDISPLAY_H
#define T100VPCDISPLAY_H

#include "T100QU32.h"


namespace T100VPC{
class T100VPCHost;

class T100VPCDisplay
{
    public:
        T100VPCDisplay(T100QU32::T100QU32*, T100VPCHost*);
        virtual ~T100VPCDisplay();

        T100BOOL            create();

    protected:

    private:
};

}

#endif // T100VPCDISPLAY_H
