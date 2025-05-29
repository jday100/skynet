#include "T100FontFrame.h"

#include <algorithm>
#include "gui/T100FontTools.h"
#include "console/T100Console.h"
#include "gui/T100FontDialog.h"
#include "gui/T100DC.h"
#include "gui/font/T100Font.h"


T100FontFrame::T100FontFrame() :
    T100Frame()
{
    //ctor
}

T100FontFrame::~T100FontFrame()
{
    //dtor
}

T100VOID T100FontFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}


T100VOID T100FontFrame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       fontsMenuPtr    = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_FONTS, L"Fonts");

    T100MenuItem*       dialogMenuPtr   = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_FONT_DIALOG, L"Font Dialog");

    T100MenuItem*       quitMenuPtr     = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBar(menuBarPtr);

    ConnectMenu(T100MENU_ID_FONTS, (T100EVENT_FUNCTION)&T100FontFrame::OnMenuFonts);

    ConnectMenu(T100MENU_ID_FONT_DIALOG, (T100EVENT_FUNCTION)&T100FontFrame::OnMenuFontDialog);

    ConnectMenu(T100MENU_ID_QUIT, (T100EVENT_FUNCTION)&T100FontFrame::OnMenuQuit);

    Connect(T100EVENT_WINDOW_PAINT, (T100EVENT_FUNCTION)&T100FontFrame::OnFramePaint);
}

T100VOID T100FontFrame::uninit()
{

}

T100VOID T100FontFrame::OnMenuFonts(T100CommandEvent& event)
{
    T100WSTRING_VECTOR      fonts;
    T100FontTools::Get(GetHWND(), fonts);

    std::sort(fonts.begin(), fonts.end());

    T100Console     console;

    for(T100WSTRING item : fonts){
        console.OutLine(item);
    }

    console.OutLine(L"你好");
}

T100VOID T100FontFrame::OnMenuFontDialog(T100CommandEvent& event)
{
    T100FontDialog      dialog;

    dialog.Create(this);
}

T100VOID T100FontFrame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}

T100VOID T100FontFrame::OnFramePaint(T100PaintEvent& event)
{
    T100DC          dc(this);
    //T100Font        font(L"Impact");
    T100Font        font(L"宋体");

    dc.SetFont(font);

    dc.DrawText(L"hello", 0, 0);
    dc.DrawText(L"宋体", 0, 0);
}
