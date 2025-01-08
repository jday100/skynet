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
        m_renderer  = T100NEW T100DX12Renderer();
        m_frame->Create(L"3DGame", title.to_wstring().c_str(), GameWindowProcedure, m_renderer);
        m_renderer->create(m_frame->GetHWND());
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

T100VOID T1003DGame::setScene(T100Scene* scene)
{
    m_scene     = scene;
}

T100Scene* T1003DGame::getScene()
{
    return m_scene;
}

T100VOID T1003DGame::setCharacter(T100Character* character)
{
    m_character = character;
}

T100Character* T1003DGame::getCharacter()
{
    return m_character;
}

T100BOOL T1003DGame::load()
{
    load_scene();
    load_character();
}

T100BOOL T1003DGame::release()
{

}

T100BOOL T1003DGame::load_scene()
{

}

T100BOOL T1003DGame::load_character()
{

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

T100BOOL T1003DGame::render()
{

}

LRESULT CALLBACK T1003DGame::GameWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T1003DGame* pGame = reinterpret_cast<T1003DGame*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(!pGame)return S_FALSE;

    switch(message)
    {
    case WM_PAINT:
        pGame->render();
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
