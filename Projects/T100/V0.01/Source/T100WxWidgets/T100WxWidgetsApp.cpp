/***************************************************************
 * Name:      T100WxWidgetsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-08-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WxWidgetsApp.h"

//(*AppHeaders
#include "T100WxWidgetsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100WxWidgetsApp);

bool T100WxWidgetsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100WxWidgetsFrame* Frame = new T100WxWidgetsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
