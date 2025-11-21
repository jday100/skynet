/***************************************************************
 * Name:      T100ViewApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ViewApp.h"

//(*AppHeaders
#include "T100ViewMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100ViewApp);

bool T100ViewApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100ViewFrame* Frame = new T100ViewFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
