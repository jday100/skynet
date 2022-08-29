/***************************************************************
 * Name:      T100FontBuilderApp.h
 * Purpose:   Defines Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100FONTBUILDERAPP_H
#define T100FONTBUILDERAPP_H

#include <wx/app.h>
#include "T100FontServe.h"
#include "T100FontView.h"


class T100FontBuilderApp : public wxApp
{
    public:
        virtual bool OnInit();

        T100FontServe       m_serve;
        T100FontView        m_view;

};

DECLARE_APP(T100FontBuilderApp)

#endif // T100FONTBUILDERAPP_H
