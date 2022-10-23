/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (2020-2023)
 * License:
 **************************************************************/

#include "T100App.h"

//(*AppHeaders
#include "T100Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100App);

bool T100App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100Frame* Frame = new T100Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
