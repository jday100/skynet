/***************************************************************
 * Name:      T100EditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-27
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100EditorApp.h"

//(*AppHeaders
#include "T100EditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100EditorApp);

bool T100EditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100EditorFrame* Frame = new T100EditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
