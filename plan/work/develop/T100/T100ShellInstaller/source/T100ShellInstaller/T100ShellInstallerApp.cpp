/***************************************************************
 * Name:      T100ShellInstallerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2025-07-31
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100ShellInstallerApp.h"

//(*AppHeaders
#include "T100ShellInstallerMain.h"
#include <wx/image.h>
//*)

#include "T100ShellWizarder.h"

IMPLEMENT_APP(T100ShellInstallerApp);

#define     T100ShellInstallerDialog            T100ShellWizarder

bool T100ShellInstallerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100ShellInstallerDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
