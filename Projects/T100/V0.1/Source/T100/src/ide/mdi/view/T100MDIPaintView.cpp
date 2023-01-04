#include "T100MDIPaintView.h"

#include <wx/stockitem.h>
#include "T100App.h"
#include "T100IDEApp.h"
#include "T100IDEView.h"
#include "T100Painter.h"
#include "T100PainterView.h"

#include "T100IDEViewManager.h"
#include "T100IDEPlatenManager.h"


namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDIPaintView, T100MDIViewBase)

BEGIN_EVENT_TABLE(T100MDIPaintView, T100MDIViewBase)
END_EVENT_TABLE()


T100MDIPaintView::T100MDIPaintView()
    :T100MDIViewBase()
{
    //ctor
    create();
}

T100MDIPaintView::~T100MDIPaintView()
{
    //dtor
    destroy();
}

T100VOID T100MDIPaintView::create()
{

}

T100VOID T100MDIPaintView::destroy()
{

}

T100BOOL T100MDIPaintView::OnCreate(wxDocument* doc, long flags)
{
    if( !wxView::OnCreate(doc, flags) ){
        return T100FALSE;
    }

    m_view = wxGetApp().getManager()->getIDE()->getView();

    m_frame = T100NEW T100MDIPaintFrame(doc, this, wxStaticCast(m_view->getFrame(), wxMDIParentFrame));
    wxASSERT(m_frame == GetFrame());

    wxBoxSizer* BoxSizer1;

    BoxSizer1 = T100NEW wxBoxSizer(wxHORIZONTAL);

    m_painter   = T100NEW T100Painter::T100Painter();

    m_painter->getView()->setParent(m_frame);

    if(m_view->getPlatenManager()->Exists(T100IDE_TYPE_PAINTER)){
        T100IDEPainterPlaten*   platen = static_cast<T100IDEPainterPlaten*>(m_view->getPlatenManager()->getPlaten(T100IDE_TYPE_PAINTER));
        m_painter->getView()->setElementsPanel(platen->getElementsPanel());
    }else{
        m_painter->getView()->setRootFrame(wxStaticCast(m_view->getFrame(), wxMDIParentFrame));
    }

    m_painter->getView()->setManager(m_view->getViewManager()->getAuiManager());
    m_painter->getView()->create();

    BoxSizer1->Add(m_painter->getView()->getPaintCtrl(), 1, wxALL|wxEXPAND, 5);

    m_frame->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_frame);
    BoxSizer1->SetSizeHints(m_frame);

    m_painter->NewFile();

    m_frame->Show();


    m_view->getPlatenManager()->Change(T100IDE_TYPE_PAINTER, m_painter);

    return T100TRUE;
}

T100VOID T100MDIPaintView::OnDraw(wxDC* dc)
{

}

T100VOID T100MDIPaintView::OnUpdate(wxView* sender, wxObject* hint)
{

}

T100BOOL T100MDIPaintView::OnClose(T100BOOL deleteWindow)
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

T100Painter::T100Painter* T100MDIPaintView::GetPainter() const
{
    return m_painter;
}

}
