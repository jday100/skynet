/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (China SuZhou)   jdayskynet@outlook.com
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#include "T100App.h"

//(*AppHeaders
#include "T100Main.h"
#include <wx/image.h>
//*)

#include "T100Setup.h"
#include "T100Log.h"
#include "T100LogAppenderConsole.h"
#include "T100LogAppenderFile.h"

#include "T100IDEApp.h"
#include "T100VPCApp.h"
#include "T100VDiskApp.h"
#include "T100FontApp.h"

#include "T100AssemblyLog.h"
#include "T100AssemblyNew.h"
#include "T100VDiskCmdParser.h"
#include "T100VDiskConsole.h"


#include "T100HelpApp.h"
#include "T100TestApp.h"


IMPLEMENT_APP(T100App);

bool T100App::OnInit()
{
    /*DON'T DELETE IT
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
    */

    log();

    T100BOOL    result      = T100TRUE;

    //memset(&m_state, 0, sizeof(m_state));

    result = wxApp::OnInit();
    if(!result){
        return T100FALSE;
    }

    wxInitAllImageHandlers();

    if(m_state.VPC){
        T100VPCApp* app = T100NEW T100VPCApp();
        app->show();
        SetTopWindow(app->getFrame());

        app->setQuit(m_state.QUIT);

        if(!m_state.FILE.empty()){
            T100DWORD offset     = 0;

            if(m_state.OFFSET.ToULongLong(&offset)){

            }
            app->run(this, m_state.FILE.ToStdString(), offset);
        }
    }

    if(m_state.FONT){
        T100FontApp* app = T100NEW T100FontApp();
        app->show();
        SetTopWindow(app->getFrame());

        if(!m_state.FILE.empty()){
            app->run(m_state.FILE.ToStdString());
        }
    }

    if(m_state.VDM){
        T100VDiskApp* app = T100NEW T100VDiskApp();
        app->show();
        SetTopWindow(app->getFrame());

        if(!m_state.FILE.empty()){
            app->run(m_state.FILE.ToStdString());
        }
    }

    if(m_state.IDE){
        T100IDEApp* app = T100NEW T100IDEApp();
        app->show();
        SetTopWindow(app->getFrame());

        if(!m_state.FILE.empty()){
            app->run(m_state.FILE.ToStdString());
        }
    }

    return result;
}

int T100App::OnRun()
{
    if(m_state.TEST){
        return test(this);
    }

    if(m_state.HELP){
        return help();
    }

    if(m_state.ASSEMBLY){
        return assembly();
    }

    if(m_state.VDISK){
        return vdisk();
    }

    return wxApp::OnRun();
}

int T100App::Run()
{
    return wxApp::OnRun();
}

int T100App::OnExit()
{
    return wxApp::OnExit();
}

void T100App::OnInitCmdLine(wxCmdLineParser& parser)
{
    parser.SetDesc(T100CmdLineDesc);
}

bool T100App::OnCmdLineParsed(wxCmdLineParser& parser)
{
    wxCmdLineSwitchState    state;

    state = parser.FoundSwitch(wxString("?"));
    if(wxCMD_SWITCH_ON == state){
        return false;
    }

    state = parser.FoundSwitch(wxString("T"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("u");
        wxString value;

        m_state.TEST    = T100TRUE;
        m_state.FLAG    = T100TRUE;

        state = parser.FoundSwitch(wxString("l"));
        if(wxCMD_SWITCH_ON == state){
            m_state.LIST    = T100TRUE;
        }else{
            if(parser.Found(name, &value)){
                m_state.UNITS   = value;
            }
        }

        state = parser.FoundSwitch(wxString("q"));
        if(wxCMD_SWITCH_ON == state){
            m_state.QUIT    = T100TRUE;
        }
    }

    state = parser.FoundSwitch(wxString("H"));
    if(wxCMD_SWITCH_ON == state){
        m_state.HELP    = T100TRUE;
        m_state.FLAG    = T100TRUE;
    }

    state = parser.FoundSwitch(wxString("V"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("f");
        wxString value;

        m_state.VPC     = T100TRUE;
        m_state.FLAG    = T100TRUE;

        if(parser.Found(name, &value)){
            m_state.FILE    = value;

            wxString name("s");
            wxString value;

            if(parser.Found(name, &value)){
                m_state.OFFSET  = value;
            }
        }

        state = parser.FoundSwitch(wxString("q"));
        if(wxCMD_SWITCH_ON == state){
            m_state.QUIT    = T100TRUE;
        }
    }

    state = parser.FoundSwitch(wxString("F"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("f");
        wxString value;

        m_state.FONT    = T100TRUE;
        m_state.FLAG    = T100TRUE;

        if(parser.Found(name, &value)){
            m_state.FILE    = value;
        }
    }

    state = parser.FoundSwitch(wxString("D"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("f");
        wxString value;

        m_state.VDISK   = T100TRUE;
        m_state.FLAG    = T100TRUE;

        if(parser.Found(name, &value)){
            m_state.FILE    = value;
        }
    }

    state = parser.FoundSwitch(wxString("M"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("f");
        wxString value;

        m_state.VDM     = T100TRUE;
        m_state.FLAG    = T100TRUE;

        if(parser.Found(name, &value)){
            m_state.FILE    = value;
        }
    }

    state = parser.FoundSwitch(wxString("I"));
    if(wxCMD_SWITCH_ON == state){
        wxString name("f");
        wxString value;

        m_state.IDE     = T100TRUE;
        m_state.FLAG    = T100TRUE;

        if(parser.Found(name, &value)){
            m_state.FILE    = value;
        }
    }

    state = parser.FoundSwitch(wxString("A"));
    if(wxCMD_SWITCH_ON == state){
        wxString inname("i");
        wxString invalue;
        wxString outname("o");
        wxString outvalue;
        wxString imname("p");
        wxString imvalue;

        m_state.ASSEMBLY    = T100TRUE;
        m_state.FLAG        = T100TRUE;

        if(parser.Found(inname, &invalue)){
            m_state.INPUT   = invalue;
        }

        if(parser.Found(outname, &outvalue)){
            m_state.OUTPUT  = outvalue;
        }

        if(parser.Found(imname, &imvalue)){
            m_state.IMPORTS.Add(imvalue);
        }
    }

    state = parser.FoundSwitch(wxString("L"));
    if(wxCMD_SWITCH_ON == state){
        m_state.LOG         = T100TRUE;
        //T100Log::m_level    = T100LOG_LEVEL_ALL;
        //test
        //T100Log::m_type     = T100LOG_BYTE;
        //T100AssemblyLog::m_type     = T100LOG_SENTENCE;
        //test
        T100Log::stop();
    }

    state = parser.FoundSwitch(wxString("E"));
    if(wxCMD_SWITCH_ON == state){
        m_state.ERR         = T100TRUE;
    }

    if(!m_state.FLAG){
        m_state.VPC         = T100TRUE;
    }

    return T100TRUE;
}

int T100App::assembly()
{
    T100Assembly    assemble;
    T100INTEGER     result;

    if(m_state.INPUT.IsEmpty()){
        result = -1;
    }else{
        T100STDSTRING   inname;
        T100STDSTRING   outname;

        //test
        if(0 != m_state.IMPORTS.size()){
            for(auto path : m_state.IMPORTS){
                assemble.add(path.ToStdString());
            }
        }


        inname = m_state.INPUT.ToStdString();
        if(m_state.OUTPUT.IsEmpty()){
            if(assemble.run(inname)){
                result = 0;
            }else{
                result = -1;
            }
        }else{
            outname = m_state.OUTPUT.ToStdString();
            if(assemble.run(inname, outname)){
                result = 0;
            }else{
                result = -1;
            }
        }
    }

    return result;
}

int T100App::vdisk()
{
    T100VDiskCmdParser  parser;
    T100VDiskConsole    vdisk;
    T100INTEGER         result;

    vdisk.setCmdParser(&parser);

    if(m_state.FILE.IsEmpty()){
        result = vdisk.run();
    }else{
        result = vdisk.run(m_state.FILE.ToStdString());
    }

    return result;
}

int T100App::help()
{
    T100HelpApp     help;

    if(help.show()){
        return 0;
    }
    return -1;
}

int T100App::test(T100App* app)
{
    T100BOOL        result;
    T100TestApp     test(app);

    if(m_state.LIST){
        result = test.list();
    }else if(m_state.UNITS.empty()){
        result = test.test_all();
    }else{
        result = test.test_unit(m_state.UNITS.ToStdString());
    }

    if(result){
        return 0;
    }
    return -1;
}

void T100App::log()
{
    T100BOOL                    result;
    T100LogAppenderConsole*     console;
    T100LogAppenderFile*        file;

    console     = T100NEW T100LogAppenderConsole();
    result      = T100Log::add(console);
    if(!result)return;

    file        = T100NEW T100LogAppenderFile(T100Setup::getLogFile());
    result      = T100Log::add(file);
    if(!result)return;

    T100Log::start();
}
