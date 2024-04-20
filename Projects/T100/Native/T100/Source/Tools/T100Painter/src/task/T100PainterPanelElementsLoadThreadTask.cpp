#include "T100PainterPanelElementsLoadThreadTask.h"

#include <wx/image.h>
#include "T100WxEventData.h"
#include "T100PainterElementsPanel.h"

T100PainterPanelElementsLoadThreadTask::T100PainterPanelElementsLoadThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100PainterPanelElementsLoadThreadTask::~T100PainterPanelElementsLoadThreadTask()
{
    //dtor
}

T100VOID T100PainterPanelElementsLoadThreadTask::setPanel(T100PainterElementsPanel* panel)
{
    m_panel = panel;
    setEvtHandler(m_panel);
}

T100VOID T100PainterPanelElementsLoadThreadTask::run()
{
    T100BOOL            result;

    T100STRING          names[1] = {
                            L"images/dot.png"
                        };

    for(T100STRING item : names){
        if(load(item)){

        }else{
            return;
        }
    }
}

T100BOOL T100PainterPanelElementsLoadThreadTask::load(T100STRING name)
{
    T100BOOL                result;
    wxImage*                image           = T100NULL;
    T100WxEventData*        data            = T100NULL;

    image   = T100NEW wxImage();
    result  = image->LoadFile(name, wxBITMAP_TYPE_PNG);

    if(result){
        wxThreadEvent       event(wxEVT_THREAD, m_panel->ID_THREAD_IMAGE);

        data    = T100NEW T100WxEventData();
        data->setData(image);

        event.SetEventObject(data);
        send(event);

    }else{
        T100DELETE  image;
    }
    return result;
}
