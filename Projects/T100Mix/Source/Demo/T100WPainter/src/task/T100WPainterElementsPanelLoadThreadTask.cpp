#include "T100WPainterElementsPanelLoadThreadTask.h"

#include <wx/image.h>
#include "T100WxEventData.h"
#include "T100WPainterElementsPanel.h"

T100WPainterElementsPanelLoadThreadTask::T100WPainterElementsPanelLoadThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WPainterElementsPanelLoadThreadTask::~T100WPainterElementsPanelLoadThreadTask()
{
    //dtor
}

T100VOID T100WPainterElementsPanelLoadThreadTask::setPanel(T100WPainterElementsPanel* panel)
{
    m_panel = panel;
    setEvtHandler(m_panel);
}

T100VOID T100WPainterElementsPanelLoadThreadTask::run()
{
    T100BOOL            result;

    T100STRING          name    = L"images/circle.png";

    wxImage*            image;

    image   = T100NEW wxImage();
    result  = image->LoadFile(name, wxBITMAP_TYPE_PNG);

    if(result){
        m_panel->ImageList1->Add(*image);

        T100WxEventData*        data;
        wxThreadEvent           event(wxEVT_THREAD, m_panel->ID_THREAD_IMAGE);

        data    = T100NEW T100WxEventData();
        event.SetEventObject(data);

        event.SetEventObject(image);

        send(event);
    }
}
