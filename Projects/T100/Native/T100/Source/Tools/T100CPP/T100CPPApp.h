/***************************************************************
 * Name:      T100CPPApp.h
 * Purpose:   Defines Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2024-09-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#ifndef T100CPPAPP_H
#define T100CPPAPP_H

#include <wx/app.h>
#include "T100CPPState.h"

class T100CPPApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual void OnInitCmdLine(wxCmdLineParser& parser);
        virtual bool OnCmdLineError(wxCmdLineParser& parser);
        virtual bool OnCmdLineParsed(wxCmdLineParser& parser);

        T100CPPState        m_state;
};

#endif // T100CPPAPP_H
