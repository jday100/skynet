#ifndef T100MDIPROJECTVIEW_H
#define T100MDIPROJECTVIEW_H

#include "T100MDIViewBase.h"
#include "T100MDIProjectFrame.h"
#include "T100Project.h"

namespace T100IDE{

class T100MDIProjectView : public T100MDIViewBase
{
    public:
        T100MDIProjectView();
        virtual ~T100MDIProjectView();

        T100PROJECT::T100Project*       GetProject() const;

        T100BOOL                        OnCreate(wxDocument* doc, long flags);
        T100VOID                        OnDraw(wxDC* dc);
        T100VOID                        OnUpdate(wxView* sender, wxObject* hint = T100NULL);
        T100BOOL                        OnClose(T100BOOL deleteWindow = T100TRUE);

    protected:
        T100VOID                        create();
        T100VOID                        destroy();

        T100MDIProjectFrame*            m_frame             = T100NULL;
        T100PROJECT::T100Project*       m_project           = T100NULL;
    private:
        DECLARE_EVENT_TABLE()
        DECLARE_DYNAMIC_CLASS(T100MDIProjectView)
};

}

#endif // T100MDIPROJECTVIEW_H
