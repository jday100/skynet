/***************************************************************
 * Name:      T100DiskToolsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-07-28
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100DiskToolsApp.h"

//(*AppHeaders
#include "T100DiskToolsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100DiskToolsApp);

bool T100DiskToolsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100DiskToolsFrame* Frame = new T100DiskToolsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
