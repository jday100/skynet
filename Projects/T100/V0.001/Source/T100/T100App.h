/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu (China SuZhou)   jdayskynet@outlook.com
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100APP_H
#define T100APP_H

#include <wx/app.h>
#include "T100AppCommon.h"
#include "T100AppState.h"


class T100App : public wxApp
{
    public:
        virtual bool            OnInit();

        virtual int             OnRun();
        virtual int             OnExit();

        int                     Run();

        virtual void            OnInitCmdLine(wxCmdLineParser&);
        virtual bool            OnCmdLineParsed(wxCmdLineParser&);

    private:
        T100AppState            m_state;

        int                     assembly();
        int                     vdisk();

        int                     help();
        int                     test(T100App*);

        void                    log();
};

DECLARE_APP(T100App)

#endif // T100APP_H
