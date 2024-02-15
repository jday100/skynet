/***************************************************************
 * Name:      T100VM64App.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-02-15
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VM64App.h"

//(*AppHeaders
#include "T100VM64Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100VM64App);

bool T100VM64App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VM64Frame* Frame = new T100VM64Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
