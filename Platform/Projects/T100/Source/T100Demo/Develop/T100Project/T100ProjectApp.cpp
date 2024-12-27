/***************************************************************
 * Name:      T100ProjectApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ProjectApp.h"

//(*AppHeaders
#include "T100ProjectMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100ProjectApp);

bool T100ProjectApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100ProjectFrame* Frame = new T100ProjectFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
