#include "T100FireGame.h"

#include "T100FireScene.h"

T100FireGame::T100FireGame()
    :T100Game()
{
    //ctor
    create();
}

T100FireGame::~T100FireGame()
{
    //dtor
    destroy();
}

T100VOID T100FireGame::create()
{
    T100FireScene*      scene   = T100NEW T100FireScene();

    scene->Load();

    SetScene(scene);
}

T100VOID T100FireGame::destroy()
{

}
