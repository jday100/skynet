/***************************************************************
 * Name:      T100App.h
 * Purpose:   Defines Application Class
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (2020-2023)
 * License:
 **************************************************************/

#ifndef T100APP_H
#define T100APP_H

#include <wx/app.h>
#include "T100ThisAppManager.h"


class T100App : public wxApp
{
    public:
        virtual bool OnInit();

        T100ThisAppManager*         getManager();

    private:
        bool Initialize(int& argc, wxChar** argv);

        T100ThisAppManager          m_manager;

};

DECLARE_APP(T100App)

#endif // T100APP_H
