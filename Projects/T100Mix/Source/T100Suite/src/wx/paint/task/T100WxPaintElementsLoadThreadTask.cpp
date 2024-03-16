#include "T100WxPaintElementsLoadThreadTask.h"

#include <wx/string.h>
#include <wx/image.h>

T100WxPaintElementsLoadThreadTask::T100WxPaintElementsLoadThreadTask()
    :T100WxThreadTask()
{
    //ctor
}

T100WxPaintElementsLoadThreadTask::~T100WxPaintElementsLoadThreadTask()
{
    //dtor
}

T100BOOL T100WxPaintElementsLoadThreadTask::run(T100VOID* paras)
{
    T100BOOL        result;
    wxString        elements[0]    = {};

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
}
