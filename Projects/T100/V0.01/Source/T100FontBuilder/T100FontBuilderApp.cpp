/***************************************************************
 * Name:      T100FontBuilderApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100FontBuilderApp.h"

//(*AppHeaders
#include "T100FontBuilderMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100FontBuilderApp);

bool T100FontBuilderApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100FontBuilderFrame* Frame = new T100FontBuilderFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
