/***************************************************************
 * Name:      T1003DEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-01-09
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorApp.h"

//(*AppHeaders
#include "T1003DEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T1003DEditorApp);

bool T1003DEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T1003DEditorFrame* Frame = new T1003DEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
