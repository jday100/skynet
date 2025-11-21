/***************************************************************
 * Name:      T100VMApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-08-06
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VMApp.h"

//(*AppHeaders
#include "T100VMMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100VMApp);

bool T100VMApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VMFrame* Frame = new T100VMFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
