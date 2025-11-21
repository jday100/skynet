/***************************************************************
 * Name:      T100PSVMApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-10
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PSVMApp.h"

//(*AppHeaders
#include "T100PSVMMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100PSVMApp);

bool T100PSVMApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100PSVMFrame* Frame = new T100PSVMFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
