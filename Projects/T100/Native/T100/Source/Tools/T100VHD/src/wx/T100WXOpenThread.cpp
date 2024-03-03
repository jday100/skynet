#include "T100WXOpenThread.h"

#include "T100VDisk.h"


T100WXOpenThread::T100WXOpenThread()
    :T100WXRunThread()
{
    //ctor
}

T100WXOpenThread::~T100WXOpenThread()
{
    //dtor
}

T100VOID T100WXOpenThread::setFileName(T100STRING file)
{
    m_filename  = file;
}

T100VOID T100WXOpenThread::setFrame(wxFrame* frame)
{
    m_frame     = frame;
}

T100VOID T100WXOpenThread::run()
{
    T100BOOL            result;
    T100VDisk           vdisk(m_filename, 0);

    result  = vdisk.state_open();
    if(result){
        result  = load();
    }


}

T100BOOL T100WXOpenThread::load()
{

}
