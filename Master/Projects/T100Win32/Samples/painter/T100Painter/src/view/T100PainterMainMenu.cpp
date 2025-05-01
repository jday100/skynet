#include "T100PainterMainMenu.h"

T100PainterMainMenu::T100PainterMainMenu()
{
    //ctor
}

T100PainterMainMenu::~T100PainterMainMenu()
{
    //dtor
}

T100VOID T100PainterMainMenu::Create(T100Frame* frame)
{
    m_framePtr      = frame;
    m_menuBarPtr    = T100NEW T100MenuBar();

    m_fileMenuPtr   = T100NEW T100Menu(m_menuBarPtr, L"File");
    m_newItemPtr    = T100NEW T100MenuItem(m_fileMenuPtr, T100MENU_ID_NEW, L"New");
    m_quitItemPtr   = T100NEW T100MenuItem(m_fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    m_framePtr->SetMenuBarPtr(m_menuBarPtr);
}

T100VOID T100PainterMainMenu::Destroy()
{
    T100SAFE_DELETE m_newItemPtr;
    T100SAFE_DELETE m_quitItemPtr;
    T100SAFE_DELETE m_fileMenuPtr;
    T100SAFE_DELETE m_menuBarPtr;
}
