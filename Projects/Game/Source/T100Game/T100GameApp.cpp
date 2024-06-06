/***************************************************************
 * Name:      T100GameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-06-05
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100GameApp.h"

//(*AppHeaders
#include "T100GameMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100GameApp);

bool T100GameApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100GameFrame* Frame = new T100GameFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
