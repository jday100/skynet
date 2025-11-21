/***************************************************************
 * Name:      T100DiagramApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-10-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100DiagramApp.h"

//(*AppHeaders
#include "T100DiagramMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100DiagramApp);

bool T100DiagramApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100DiagramFrame* Frame = new T100DiagramFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
