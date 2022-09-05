#ifndef T100REGISTEREVENTDATA_H
#define T100REGISTEREVENTDATA_H

#include <wx/event.h>
#include "T100Common.h"


class T100RegisterEventData : public wxObject
{
    public:
        T100RegisterEventData();
        virtual ~T100RegisterEventData();

        T100WORD            TYPE;
        T100WORD            VALUE;

    protected:

    private:
};

#endif // T100REGISTEREVENTDATA_H
