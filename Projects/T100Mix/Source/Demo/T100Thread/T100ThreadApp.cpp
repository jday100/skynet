/***************************************************************
 * Name:      T100ThreadApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ThreadApp.h"

//(*AppHeaders
#include "T100ThreadMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100ThreadApp);

bool T100ThreadApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100ThreadFrame* Frame = new T100ThreadFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
