#ifndef T100IDEPROJECTVIEW_H
#define T100IDEPROJECTVIEW_H

#include <wx/docmdi.h>
#include "T100Common.h"


class T100IDEProjectView : public wxView
{
    public:
        T100IDEProjectView();
        virtual ~T100IDEProjectView();

        T100VOID            OnDraw(wxDC* dc);

    protected:

    private:
};

#endif // T100IDEPROJECTVIEW_H
