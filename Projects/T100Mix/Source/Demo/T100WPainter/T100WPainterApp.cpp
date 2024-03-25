/***************************************************************
 * Name:      T100WPainterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-03-24
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100WPainterApp.h"
#include "T100WPainter.h"
#include "T100WPainterView.h"

//(*AppHeaders
#include "T100WPainterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100WPainterApp);

/*
bool T100WPainterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100WPainterFrame* Frame = new T100WPainterFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
*/

bool T100WPainterApp::OnInit()
{

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        T100WPainter* painter = new T100WPainter();

        painter->getView()->show();
    	SetTopWindow(painter->getView()->getFrame());
    }

    return wxsOK;

}
