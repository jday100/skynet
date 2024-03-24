#include "T100WxPaintElementsLoadThreadTask.h"

#include <wx/string.h>
#include <wx/image.h>
#include "common\T100StringTypes.h"
#include "T100WxPaintElementsPanel.h"
#include "T100WxEventData.h"


T100WxPaintElementsLoadThreadTask::T100WxPaintElementsLoadThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WxPaintElementsLoadThreadTask::~T100WxPaintElementsLoadThreadTask()
{
    //dtor
}

T100VOID T100WxPaintElementsLoadThreadTask::run()
{
    T100BOOL            result;

    T100WCHAR*          elements[5] = {
        L"images\\circle.png"
    };

    for(T100WCHAR* item : elements){
        if(item){
            wxImage*    image   = T100NEW wxImage();

            result  = image->LoadFile(item, wxBITMAP_TYPE_PNG);
            if(result){
                send(image);
            }else{
                return;
            }
        }else{

        }
    }


    /*
    T100BOOL        result;
    wxString        elements[1]    = {
        L"images\\circle.png"
    };

    for(wxString item : elements){
        if(item.empty()){

        }else{
            wxImage*    image   = T100NEW wxImage();

            result  = image->LoadFile(item, wxBITMAP_TYPE_PNG);
            if(result){

            }else{
                return T100FALSE;
            }
        }
    }
    */
}

T100VOID T100WxPaintElementsLoadThreadTask::send(T100VOID* object)
{
    T100WxPaintElementsPanel*   panel       = T100NULL;

    panel   = dynamic_cast<T100WxPaintElementsPanel*>(getWindow());

    if(panel){
        wxThreadEvent       event(wxEVT_THREAD, panel->ID_THREAD_IMAGE);

        T100WxEventData*    data        = T100NEW T100WxEventData();

        data->setObject(object);
        event.SetEventObject(data);

        wxQueueEvent(getWindow(), event.Clone());
    }
}
