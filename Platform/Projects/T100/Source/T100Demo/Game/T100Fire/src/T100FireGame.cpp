#include "T100FireGame.h"

T100FireGame::T100FireGame(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpArgument, int nCmdShow)
    :T1003DGame(hThisInstance, hPrevInstance, lpArgument, nCmdShow)
{
    //ctor
    init();
}

T100FireGame::~T100FireGame()
{
    //dtor
    uninit();
}

T100VOID T100FireGame::init()
{

}

T100VOID T100FireGame::uninit()
{

}

T100BOOL T100FireGame::create(T100WORD width, T100WORD height, T100WString title)
{
    return T1003DGame::create(width, height, title);
}

T100BOOL T100FireGame::destroy()
{

}

T100BOOL T100FireGame::show()
{
    return T1003DGame::show();
}

T100INT T100FireGame::run()
{
    return T1003DGame::run();
}
