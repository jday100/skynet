#ifndef T100VDISKVIEW_H
#define T100VDISKVIEW_H

#include <wx/frame.h>
#include "T100VDiskCommon.h"


class T100VDiskView
{
    public:
        T100VDiskView();
        virtual ~T100VDiskView();

        T100VOID            setFrame(wxFrame*);
        wxFrame*            getFrame();

    protected:

    private:
        wxFrame*            m_frame         = T100NULL;

};

#endif // T100VDISKVIEW_H
