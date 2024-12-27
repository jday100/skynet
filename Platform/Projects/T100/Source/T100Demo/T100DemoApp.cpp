/***************************************************************
 * Name:      T100DemoApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100DemoApp.h"

//(*AppHeaders
#include "T100DemoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100DemoApp);

bool T100DemoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100DemoFrame* Frame = new T100DemoFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
