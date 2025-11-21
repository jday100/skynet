#include "T100FontServer.h"

#include "T100FontPanel.h"
#include "T100FontBuilder.h"
#include "extension/T100ExtensionFrame.h"

T100FontServer::T100FontServer() :
    T100ExtensionServer()
{
    //ctor
}

T100FontServer::~T100FontServer()
{
    //dtor
}

T100VOID T100FontServer::Start()
{
    T100ExtensionServer::Start();
}

T100VOID T100FontServer::Stop()
{
    T100ExtensionServer::Stop();
}

T100VOID T100FontServer::Load()
{
    T100ExtensionFrame*     frame   = dynamic_cast<T100ExtensionFrame*>(Find(T100FONT_BUILDER_VIEW_MAIN_FRAME));
    if(!frame){
        return;
    }
    T100FontPanel*          panel       = T100NEW T100FontPanel();
    if(!panel){
        return;
    }

    panel->Create(frame->GetFrame());
    panel->Show();

    frame->GetFrame()->SetSize(800, 600);
}
