/***************************************************************
 * Name:      T100ZipApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-09-29
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ZipApp.h"

//(*AppHeaders
#include "T100ZipMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100ZipApp);

bool T100ZipApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100ZipDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
