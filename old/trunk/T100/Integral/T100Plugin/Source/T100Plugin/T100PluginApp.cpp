/***************************************************************
 * Name:      T100PluginApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PluginApp.h"

//(*AppHeaders
#include "T100PluginMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100PluginApp);

bool T100PluginApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100PluginFrame* Frame = new T100PluginFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
