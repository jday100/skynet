/***************************************************************
 * Name:      T100NeuroidApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-12-18
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100NeuroidApp.h"

//(*AppHeaders
#include "T100NeuroidMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100NeuroidApp);

bool T100NeuroidApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100NeuroidFrame* Frame = new T100NeuroidFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
