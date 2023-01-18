/***************************************************************
 * Name:      T100Main.h
 * Purpose:   Defines Application Frame
 * Author:    ZhengFeng Qu (jdayskynet@outlook.com)
 * Created:   2020-08-16
 * Copyright: ZhengFeng Qu (2020-2023)
 * License:
 **************************************************************/

#ifndef T100MAIN_H
#define T100MAIN_H

//(*Headers(T100Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)
#include <mutex>
#include <condition_variable>
#include "T100Common.h"
#include "T100FontBuilder.h"
#include "T100VPC.h"

class T100Frame: public wxFrame
{
    public:

        T100Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~T100Frame();

        T100VOID            wait();
        T100WORD            getReturn();

        static const long ID_THREAD_CLOSE;
        static const long ID_THREAD_FONT;
        static const long ID_THREAD_VPC;
        static const long ID_THREAD_PAINT;

    protected:
        void OnThreadClose(wxThreadEvent& event);
        void OnThreadFont(wxThreadEvent& event);
        void OnThreadVPC(wxThreadEvent& event);
        void OnThreadPaint(wxThreadEvent& event);

        void OnResize(wxSizeEvent& event);

    private:
        T100WORD                    m_return;
        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

        T100FontBuilder::T100FontBuilder*       m_builder           = T100NULL;
        T100VPC::T100VPC*                       m_vpc               = T100NULL;

        T100BOOL    font_quit(void*);
        T100BOOL    vpc_quit(void*);


        //(*Handlers(T100Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(T100Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(T100Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // T100MAIN_H
