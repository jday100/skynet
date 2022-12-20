#ifndef T100EVENTDATA_H
#define T100EVENTDATA_H

#include <wx/event.h>
#include "T100Common.h"

namespace T100VPC{

class T100EventData : public wxObject
{
    public:
        T100EventData();
        virtual ~T100EventData();

        T100WORD            OFFSET;
        T100WORD            VALUE;

    protected:

    private:
};

}

#endif // T100EVENTDATA_H
