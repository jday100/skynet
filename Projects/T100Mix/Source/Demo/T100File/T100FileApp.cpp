/***************************************************************
 * Name:      T100FileApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-04-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100FileApp.h"

//(*AppHeaders
#include "T100FileMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100FileApp);

bool T100FileApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100FileFrame* Frame = new T100FileFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
