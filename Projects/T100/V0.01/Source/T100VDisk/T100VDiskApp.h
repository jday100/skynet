/***************************************************************
 * Name:      T100VDiskApp.h
 * Purpose:   Defines Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2022-07-23
 * Copyright: ZhengFeng Qu (China SuZhou)
 * License:
 **************************************************************/

#ifndef T100VDISKAPP_H
#define T100VDISKAPP_H

#include <wx/app.h>
#include "T100VDiskServe.h"
#include "T100VDiskView.h"


class T100VDiskApp : public wxApp
{
    public:
        virtual bool OnInit();

        T100VDiskServe          m_serve;
        T100VDiskView           m_view;

};

DECLARE_APP(T100VDiskApp)

#endif // T100VDISKAPP_H
