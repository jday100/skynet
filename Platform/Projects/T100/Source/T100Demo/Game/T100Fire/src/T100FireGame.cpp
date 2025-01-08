#include "T100FireGame.h"

#include "T100FireScene.h"

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
    //load();
}

T100VOID T100FireGame::uninit()
{
    release();
}

T100BOOL T100FireGame::create(T100WORD width, T100WORD height, T100WString title)
{
    return T1003DGame::create(width, height, title);
}

T100BOOL T100FireGame::destroy()
{

}

T100BOOL T100FireGame::load()
{
    T100FireScene*      scene       = T100NEW T100FireScene();

    scene->load();

    setScene(scene);

    T1003DGame::load();
}

T100BOOL T100FireGame::release()
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
