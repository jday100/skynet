#include "../../../include/vpc/view/T100VPCScreen.h"

//(*InternalHeaders(T100VPCScreen)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/rawbmp.h>
#include "T100VPCCommon.h"
#include "T100VPCServe.h"
#include "T100VPCView.h"


//(*IdInit(T100VPCScreen)
const long T100VPCScreen::ID_TIMER_SCREEN = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100VPCScreen,wxFrame)
	//(*EventTable(T100VPCScreen)
	//*)
END_EVENT_TABLE()

T100VPCScreen::T100VPCScreen(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    m_frame = dynamic_cast<T100VPCFrame*>(parent);
	BuildContent(parent,id,pos,size);

	SetClientSize(size);
	Move(wxDefaultPosition);
}

void T100VPCScreen::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCScreen)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	T100VPCTimer.SetOwner(this, ID_TIMER_SCREEN);
	T100VPCTimer.Start(1, false);

	Connect(ID_TIMER_SCREEN,wxEVT_TIMER,(wxObjectEventFunction)&T100VPCScreen::OnT100VPCTimerTrigger);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100VPCScreen::OnPaint);
	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&T100VPCScreen::OnEraseBackground);
	//*)
}

T100VPCScreen::~T100VPCScreen()
{
	//(*Destroy(T100VPCScreen)
	//*)
}

T100BOOL T100VPCScreen::run()
{
    T100VPCServe*   serve       = T100NULL;

    serve = dynamic_cast<T100VPCServe*>(m_frame->getView()->getServe());

    if(serve){
        return serve->run();
    }

    return T100FALSE;


    //T100VPCServe*   serve       = T100NULL;

    serve = dynamic_cast<T100VPCServe*>(m_frame->getView()->getServe());

    /*
    if(serve){
        return serve->run(m_frame);
    }
    */

    if(serve){
        //if(serve->create()){
            if(serve->bind(m_frame->getView(), serve, m_frame)){
                return serve->run();
            }
        //}
    }

    return T100FALSE;
}

T100BOOL T100VPCScreen::start()
{
    return T100TRUE;

    T100VPCServe*   serve       = T100NULL;

    serve = dynamic_cast<T100VPCServe*>(m_frame->getView()->getServe());



    if(serve){
        if(serve->create(m_frame->getView(), T100NULL)){
            if(serve->bind(m_frame->getView(), serve, m_frame)){
                return serve->start();
            }
        }
    }

    return T100FALSE;
}

T100BOOL T100VPCScreen::stop()
{
    return T100TRUE;

    T100VPCServe* serve = (T100VPCServe*)(m_frame->getView()->getServe());

    if(serve){
        return serve->stop();
    }

    return T100FALSE;
}

T100BOOL T100VPCScreen::paint()
{
    static char         buffer[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
    wxMemoryDC          memory;
    wxBufferedPaintDC   dc(this);

    T100VPCServe*       serve;
    T100WORD*           screen    = T100NULL;

    serve = (T100VPCServe*)m_frame->getView()->getServe();
    screen = serve->getScreen();

    if(!screen){
        return T100FALSE;
    }

    memcpy(buffer, screen, sizeof(buffer));

    wxBitmap bitmap(buffer, SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    memory.SelectObject(bitmap);
    dc.Blit(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &memory, 0, 0);
    memory.SelectObject(wxNullBitmap);

    //bitmap.SaveFile("bitmap.bmp", wxBITMAP_TYPE_BMP);

    this->Refresh();

    return T100FALSE;
}

T100BOOL T100VPCScreen::draw()
{
    static wxBitmap     bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
    wxMemoryDC          memory;
    wxBufferedPaintDC   dc(this);

    T100WORD* screen = T100NULL;

    //screen = m_frame->getView()->getServe()->getScreen();

    if(!screen){
        return T100FALSE;
    }

    //draw(screen, bitmap);

    memory.SelectObject(bitmap);
    //memory.SetBackground(*wxBLACK_BRUSH);
    //memory.Clear();


    dc.Blit(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &memory, 0, 0);

    memory.SelectObject(wxNullBitmap);

    //bitmap.SaveFile("bitmap.bmp", wxBITMAP_TYPE_BMP);

    //this->Refresh();

    return T100FALSE;
}


void T100VPCScreen::OnT100VPCTimerTrigger(wxTimerEvent& event)
{
    this->Refresh();
}

void T100VPCScreen::OnPaint(wxPaintEvent& event)
{
    //T100Log::info(T100VPC_HINT_SCREEN_REFRESH);

    paint();
}

void T100VPCScreen::OnEraseBackground(wxEraseEvent& event)
{
}
