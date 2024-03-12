/***************************************************************
 * Name:      T100DiskerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-12
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100DiskerApp.h"

//(*AppHeaders
#include "T100DiskerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100DiskerApp);

bool T100DiskerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100DiskerFrame* Frame = new T100DiskerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
