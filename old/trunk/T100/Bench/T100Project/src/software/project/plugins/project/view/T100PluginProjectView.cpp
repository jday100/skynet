#include "T100PluginProjectView.h"

#include "T100ProjectMain.h"

T100PluginProjectView::T100PluginProjectView()
{
    //ctor
}

T100PluginProjectView::~T100PluginProjectView()
{
    //dtor
}

T100VOID T100PluginProjectView::Create(T100ProjectFrame* frame)
{
    m_panel     = T100NEW T100PluginProjectProjectPanel(frame);

    frame->m_sizer.Add(m_panel, 1, wxALL|wxEXPAND, 0);
    frame->SetSizer(&frame->m_sizer);
    frame->m_sizer.Fit(frame);
    frame->m_sizer.SetSizeHints(frame);

    frame->Maximize();
}

T100VOID T100PluginProjectView::Destroy()
{
    T100SAFE_DELETE(m_panel);
}

T100VOID T100PluginProjectView::Append(T100ProjectInfo& info)
{
    m_panel->Append(info);
}

T100VOID T100PluginProjectView::Update(T100PROJECT_VESSEL& projects)
{
    m_panel->Update(projects);
}
