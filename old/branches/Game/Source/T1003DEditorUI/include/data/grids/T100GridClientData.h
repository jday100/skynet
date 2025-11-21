#ifndef T100GRIDCLIENTDATA_H
#define T100GRIDCLIENTDATA_H

#include <wx/propgrid/propgrid.h>
#include "T100Common.h"

class T100GridClientData : public wxClientData
{
    public:
        T100GridClientData(wxPropertyGrid*);
        virtual ~T100GridClientData();

        virtual T100VOID            Update(wxPGProperty*) = 0;

    protected:
        wxPropertyGrid*             m_gridPtr           = T100NULL;

    private:
};

#endif // T100GRIDCLIENTDATA_H
