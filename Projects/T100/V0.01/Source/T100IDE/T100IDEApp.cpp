/***************************************************************
 * Name:      T100IDEApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100IDEApp.h"

//(*AppHeaders
#include "T100IDEMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100IDEApp);

bool T100IDEApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100IDEFrame* Frame = new T100IDEFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
