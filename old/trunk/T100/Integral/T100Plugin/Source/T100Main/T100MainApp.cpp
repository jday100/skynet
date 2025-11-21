/***************************************************************
 * Name:      T100MainApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100MainApp.h"

//(*AppHeaders
#include "T100MainMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100MainApp);

bool T100MainApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100MainFrame* Frame = new T100MainFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
