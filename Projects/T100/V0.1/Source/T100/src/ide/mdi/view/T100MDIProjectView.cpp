#include "T100MDIProjectView.h"

#include <wx/stockitem.h>
#include "T100App.h"
#include "T100IDEApp.h"
#include "T100IDEView.h"
#include "T100Project.h"
#include "T100ProjectView.h"

#include "T100IDEViewManager.h"
#include "T100IDEPlatenManager.h"


namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDIProjectView, T100MDIViewBase)

BEGIN_EVENT_TABLE(T100MDIProjectView, T100MDIViewBase)
END_EVENT_TABLE()

T100MDIProjectView::T100MDIProjectView()
    :T100MDIViewBase()
{
    //ctor
    create();
}

T100MDIProjectView::~T100MDIProjectView()
{
    //dtor
    destroy();
}

T100VOID T100MDIProjectView::create()
{

}

T100VOID T100MDIProjectView::destroy()
{

}


T100BOOL T100MDIProjectView::OnCreate(wxDocument* doc, long flags)
{
    if( !wxView::OnCreate(doc, flags) ){
        return T100FALSE;
    }

    m_view = wxGetApp().getManager()->getIDE()->getView();

    m_frame = T100NEW T100MDIProjectFrame(doc, this, wxStaticCast(m_view->getFrame(), wxMDIParentFrame));
    wxASSERT(m_frame == GetFrame());
    m_frame->setView(m_view);

    wxBoxSizer* BoxSizer1;

    BoxSizer1   = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_project   = T100NEW T100PROJECT::T100Project();

    m_project->setParent(m_frame);
    m_project->setRootFrame(wxStaticCast(m_view->getFrame(), wxMDIParentFrame));

    m_project->create();
    m_project->getView()->setManager(m_view->getViewManager()->getAuiManager());

    if(m_view->getPlatenManager()->Exists(T100IDE_TYPE_PROJECT)){
        T100IDEProjectPlaten*   platen = static_cast<T100IDEProjectPlaten*>(m_view->getPlatenManager()->getPlaten(T100IDE_TYPE_PROJECT));

        //m_project->getView()->setElementsPanel(platen->getElementsPanel());
        //m_project->getView()->setPropertiesPanel(platen->getPropertiesPanel());

        platen->setProject(m_project);
    }else{
        T100IDEProjectPlaten*   platen = static_cast<T100IDEProjectPlaten*>(m_view->getPlatenManager()->getPlaten(T100IDE_TYPE_PROJECT));

        platen->setProject(m_project);

        platen->create();
    }

    BoxSizer1->Add(m_project->getView()->getProjectCtrl(), 1, wxALL|wxEXPAND, 5);

    m_frame->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_frame);
    BoxSizer1->SetSizeHints(m_frame);

    m_project->NewFile();

    m_frame->setProject(m_project);
    m_frame->Show();


    m_view->getPlatenManager()->Change(T100IDE_TYPE_PROJECT);

    return T100TRUE;
}

T100VOID T100MDIProjectView::OnDraw(wxDC* dc)
{

}

T100VOID T100MDIProjectView::OnUpdate(wxView* sender, wxObject* hint)
{

}

T100BOOL T100MDIProjectView::OnClose(T100BOOL deleteWindow)
{
    if( !wxView::OnClose(deleteWindow) ){
        return T100FALSE;
    }

    Activate(T100FALSE);

    if( deleteWindow ){
        GetFrame()->Destroy();
        SetFrame(T100NULL);
    }

    return T100TRUE;
}

T100PROJECT::T100Project* T100MDIProjectView::GetProject() const
{
    return m_project;
}

}
