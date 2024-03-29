#include "T100PainterView.h"

#include <wx/filedlg.h>
#include "T100PainterFrame.h"

namespace T100Painter{

T100PainterView::T100PainterView()
{
    //ctor
}

T100PainterView::~T100PainterView()
{
    //dtor
    destroy();
}

T100BOOL T100PainterView::create()
{
    if(m_parent){
        m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_parent);
        if(m_root){
            m_elements_panel    = T100NEW T100PainterElementsPanel(m_root);
            m_properties_panel  = T100NEW T100PainterPropertiesPanel(m_root);
            m_elements          = T100NEW T100ElementManager();
            m_elements->init();
        }
    }else{
        m_manager   = T100NEW wxAuiManager();
        m_frame     = T100NEW T100PainterFrame(T100NULL, wxID_ANY, wxDefaultPosition, wxSize(800, 600));

        m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, _T("ID_SCROLLEDWINDOW1"));
        m_elements_panel    = T100NEW T100PainterElementsPanel(m_frame);
        m_properties_panel  = T100NEW T100PainterPropertiesPanel(m_frame);

        m_manager->SetFrame(m_frame);
        m_manager->AddPane(m_paint, wxAuiPaneInfo().Name(wxT("Paint")).CenterPane());
        m_manager->AddPane(m_elements_panel, wxAuiPaneInfo().Name(wxT("Elements")).Left());
        m_manager->AddPane(m_properties_panel, wxAuiPaneInfo().Name(wxT("Properties")).Left());

        m_elements      = T100NEW T100ElementManager();
        m_elements->init();
    }

    return T100TRUE;
}

T100BOOL T100PainterView::create_alone()
{
    m_manager   = T100NEW wxAuiManager();
    m_frame     = T100NEW T100PainterFrame(T100NULL, wxID_ANY, wxDefaultPosition, wxSize(800, 600));

    m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, _T("ID_SCROLLEDWINDOW1"));
    m_elements_panel    = T100NEW T100PainterElementsPanel(m_frame);
    m_properties_panel  = T100NEW T100PainterPropertiesPanel(m_frame);

    m_manager->SetFrame(m_frame);
    m_manager->AddPane(m_paint, wxAuiPaneInfo().Name(wxT("Paint")).CenterPane());
    m_manager->AddPane(m_elements_panel, wxAuiPaneInfo().Name(wxT("Elements")).BestSize(400, -1).Left());
    m_manager->AddPane(m_properties_panel, wxAuiPaneInfo().Name(wxT("Properties")).BestSize(400, -1).Left());

    m_elements      = T100NEW T100ElementManager();
    m_elements->init();

    return T100TRUE;
}

T100BOOL T100PainterView::create_embed()
{
    m_paint     = T100NEW T100WxWidgets::T100PaintCtrl(m_parent);
    if(m_root){
        m_elements_panel    = T100NEW T100PainterElementsPanel(m_root);
        m_properties_panel  = T100NEW T100PainterPropertiesPanel(m_root);
        m_elements          = T100NEW T100ElementManager();
        m_elements->init();
    }

    return T100TRUE;
}

T100VOID T100PainterView::destroy()
{
    T100SAFE_DELETE(m_paint);
    T100SAFE_DELETE(m_frame);
    T100SAFE_DELETE(m_manager);
    T100SAFE_DELETE(m_elements);
}

T100VOID T100PainterView::setParent(wxWindow* parent)
{
    m_parent = parent;
}

T100VOID T100PainterView::setRootFrame(wxFrame* frame)
{
    m_root = frame;
}

T100VOID T100PainterView::setManager(wxAuiManager* manager)
{
    m_manager = manager;
}

T100VOID T100PainterView::show()
{
    if(m_frame){
        m_frame->Show();
    }

    if(m_manager){
        m_manager->Update();
    }
}

///

T100BOOL T100PainterView::OpenFile(T100STRING& file)
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    file = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T100PainterView::SaveAsFile(T100STRING& file)
{
    wxFileDialog        dialog(m_frame, _("Please select a file"), "", "", "Diagram files(*.dgm)|*.dgm", wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _("Select a file:"));

    if(wxID_CANCEL == dialog.ShowModal())return T100FALSE;

    file = dialog.GetPath().ToStdWstring();

    return T100TRUE;
}

T100BOOL T100PainterView::ShowElements()
{
    m_manager->GetPane(m_elements_panel).Show();
    m_manager->Update();
}

T100BOOL T100PainterView::ShowProperties()
{
    m_manager->GetPane(m_properties_panel).Show();
    m_manager->Update();
}

T100BOOL T100PainterView::Quit()
{
    if(m_manager){
        m_manager->UnInit();
    }

    if(m_frame){
        m_frame->Destroy();
    }

    if(m_callback){
        (m_callback_frame->*m_callback)(T100NULL);
    }

    return T100TRUE;
}

T100ElementManager* T100PainterView::getElementManager()
{
    return m_elements;
}

T100VOID T100PainterView::setElementsPanel(T100PainterElementsPanel* panel)
{
    m_elements_panel = panel;
}

T100PainterElementsPanel* T100PainterView::getElementsPanel()
{
    return m_elements_panel;
}

T100VOID T100PainterView::setPropertiesPanel(T100PainterPropertiesPanel* panel)
{
    m_properties_panel = panel;
}

T100PainterPropertiesPanel* T100PainterView::getPropertiesPanel()
{
    return m_properties_panel;
}

T100WxWidgets::T100PaintCtrl* T100PainterView::getPaintCtrl()
{
    return m_paint;
}

T100BOOL T100PainterView::Append(wxString panel, T100ElementBase* element)
{
    T100BOOL        result          = T100FALSE;

    result = m_elements_panel->Append(panel, element);

    if(result){
        result = m_elements->Append(element);
    }

    return result;
}

T100BOOL T100PainterView::CloseFile()
{
    T100BOOL        result          = T100TRUE;

    if(m_paint){
        m_paint->Clear();
    }

    if(m_frame){
        result = m_frame->reset_menu();
    }else{
        result = T100FALSE;
    }

    if(m_properties_panel){
        m_properties_panel->Clear();
    }

    return result;
}

T100BOOL T100PainterView::LoadFile(T100DiagramInfo* diagram)
{
    m_paint->Load(diagram->getElements());
    m_paint->Change(T100CANVAS_STATE_COMMON);
    m_paint->Refresh();
    return T100TRUE;
}

T100BOOL T100PainterView::UpdateMenu()
{
    if(m_frame){
        m_frame->update_menu();
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100PainterView::setCallback(wxFrame* frame, T100WxWidgets::T100FRAME_CALLBACK callback)
{
    m_callback_frame    = frame;
    m_callback          = callback;
}


}
