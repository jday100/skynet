#include "T1003DGame.h"

T1003DGame::T1003DGame(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpArgument, int nCmdShow)
{
    //ctor
    init(hThisInstance, hPrevInstance, lpArgument, nCmdShow);
}

T1003DGame::~T1003DGame()
{
    //dtor
    uninit();
}

T100VOID T1003DGame::init(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpArgument, int nCmdShow)
{
    m_frame = T100NEW T100ApplicationWindow(hThisInstance, hPrevInstance, lpArgument, nCmdShow);
}

T100VOID T1003DGame::uninit()
{

}

T100BOOL T1003DGame::create(T100WORD width, T100WORD height, T100WString title)
{
    if(m_frame){
        m_frame->Create(L"3DGame", title.to_wstring().c_str());
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T1003DGame::destroy()
{
    if(m_frame){
        T100SAFE_DELETE m_frame;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T1003DGame::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100INT T1003DGame::run()
{
    return m_frame->Run();
}
