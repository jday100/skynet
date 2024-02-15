/***************************************************************
 * Name:      T100VHDApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VHDApp.h"

//(*AppHeaders
#include "T100VHDMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100VHDApp);

bool T100VHDApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VHDFrame* Frame = new T100VHDFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
