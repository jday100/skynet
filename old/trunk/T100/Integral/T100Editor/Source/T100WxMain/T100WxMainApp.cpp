/***************************************************************
 * Name:      T100WxMainApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WxMainApp.h"

//(*AppHeaders
#include "T100WxMainMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100WxMainApp);

bool T100WxMainApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100WxMainFrame* Frame = new T100WxMainFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
