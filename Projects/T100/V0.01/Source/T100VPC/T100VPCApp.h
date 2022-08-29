/***************************************************************
 * Name:      T100VPCApp.h
 * Purpose:   Defines Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100VPCAPP_H
#define T100VPCAPP_H

#include <wx/app.h>
#include "T100VPCServe.h"
#include "T100VPCView.h"


class T100VPCApp : public wxApp
{
    public:
        virtual bool OnInit();

        T100VPCServe        m_serve;
        T100VPCView         m_view;

};

DECLARE_APP(T100VPCApp)

#endif // T100VPCAPP_H
