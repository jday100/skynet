/***************************************************************
 * Name:      T100FireApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100FireApp.h"

//(*AppHeaders
#include "T100FireMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100FireApp);

bool T100FireApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100FireFrame* Frame = new T100FireFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
