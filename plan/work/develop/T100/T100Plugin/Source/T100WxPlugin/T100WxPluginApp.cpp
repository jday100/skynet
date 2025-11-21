/***************************************************************
 * Name:      T100WxPluginApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WxPluginApp.h"

//(*AppHeaders
#include "T100WxPluginMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100WxPluginApp);

bool T100WxPluginApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100WxPluginFrame* Frame = new T100WxPluginFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
