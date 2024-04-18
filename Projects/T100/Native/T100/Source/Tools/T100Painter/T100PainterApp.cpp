/***************************************************************
 * Name:      T100PainterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-04-14
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100PainterApp.h"
#include "T100Painter.h"
#include "T100PainterView.h"

//(*AppHeaders
#include "T100PainterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100PainterApp);

/*
bool T100PainterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100PainterFrame* Frame = new T100PainterFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
*/

bool T100PainterApp::OnInit()
{

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        T100Painter* painter = new T100Painter();

        painter->getView()->show();
    	SetTopWindow(painter->getView()->getFrame());
    }

    return wxsOK;

}
