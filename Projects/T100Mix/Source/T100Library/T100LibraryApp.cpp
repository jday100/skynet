/***************************************************************
 * Name:      T100LibraryApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-12
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100LibraryApp.h"

//(*AppHeaders
#include "T100LibraryMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100LibraryApp);

bool T100LibraryApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100LibraryFrame* Frame = new T100LibraryFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
