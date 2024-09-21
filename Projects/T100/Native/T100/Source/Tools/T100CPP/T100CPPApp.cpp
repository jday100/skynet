/***************************************************************
 * Name:      T100CPPApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-09-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100CPPApp.h"

//(*AppHeaders
#include "T100CPPMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100CPPApp);

bool T100CPPApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100CPPFrame* Frame = new T100CPPFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
