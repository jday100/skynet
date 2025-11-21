/***************************************************************
 * Name:      T1003DEditorUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-03-02
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T1003DEditorUIApp.h"

//(*AppHeaders
#include "T1003DEditorUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T1003DEditorUIApp);

bool T1003DEditorUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T1003DEditorUIFrame* Frame = new T1003DEditorUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
