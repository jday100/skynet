/***************************************************************
 * Name:      T100NativeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100NativeApp.h"

//(*AppHeaders
#include "T100NativeMain.h"
#include <wx/image.h>
//*)

#include "T100Fire.h"

IMPLEMENT_APP(T100NativeApp);

bool T100NativeApp::OnInit()
{
    /*
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100NativeFrame* Frame = new T100NativeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
    */
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        T100Fire* fire = T100NEW T100Fire();
        fire->Show();
        SetTopWindow(fire->GetFrame());
    }
    return wxsOK;
}
