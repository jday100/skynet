/***************************************************************
 * Name:      T100SuiteApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-12
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100SuiteApp.h"

//(*AppHeaders
#include "T100SuiteMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100SuiteApp);

bool T100SuiteApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100SuiteFrame* Frame = new T100SuiteFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
