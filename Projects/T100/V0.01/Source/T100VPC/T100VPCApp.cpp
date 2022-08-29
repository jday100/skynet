/***************************************************************
 * Name:      T100VPCApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100VPCApp.h"

//(*AppHeaders
#include "T100VPCMain.h"
#include <wx/image.h>
//*)

#include "T100VPCCallback.h"


IMPLEMENT_APP(T100VPCApp);

bool T100VPCApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VPCFrame* Frame = new T100VPCFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
