/***************************************************************
 * Name:      T100WxEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-11-20
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WxEditorApp.h"

//(*AppHeaders
#include "T100WxEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100WxEditorApp);

bool T100WxEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100WxEditorFrame* Frame = new T100WxEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
