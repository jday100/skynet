/***************************************************************
 * Name:      T100CPPApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-09-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100CPPApp.h"

//(*AppHeaders
#include "T100CPPMain.h"
#include <wx/image.h>
//*)

#include "T100CPPCommon.h"
#include "T100CPPThisApp.h"

IMPLEMENT_APP(T100CPPApp);

bool T100CPPApp::OnInit()
{
    /*DON'T DELETE IT
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100CPPFrame* Frame = new T100CPPFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    */

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        T100CPPThisApp* app = new T100CPPThisApp();
        app->run(m_state);
    }
    return wxsOK;

}

void T100CPPApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(T100CPPCmdLineDesc);
}

bool T100CPPApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    wxCmdLineSwitchState    state;

    state = parser.FoundSwitch(wxString("?"));
    if(wxCMD_SWITCH_ON == state){
        return false;
    }

    state = parser.FoundSwitch(wxString("T"));
    if(wxCMD_SWITCH_ON == state){
        m_state.TEST    = true;
        return true;
    }

    return false;
}

bool T100CPPApp::OnCmdLineError(wxCmdLineParser& parser)
{
    return false;
}
