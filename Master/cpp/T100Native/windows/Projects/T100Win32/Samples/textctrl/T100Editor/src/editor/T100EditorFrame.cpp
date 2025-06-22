#include "T100EditorFrame.h"

#include "gui/T100FontDialog.h"
#include "gui/T100FillLayout.h"
#include "gui/T100OpenDialog.h"
#include "gui/T100SaveDialog.h"
#include "storage/file/text/T100TextFile.h"
#include "storage/file/text/T100TextFileReader.h"

T100EditorFrame::T100EditorFrame() :
    T100Frame()
{
    //ctor
}

T100EditorFrame::~T100EditorFrame()
{
    //dtor
}

T100TextCtrl* T100EditorFrame::GetTextCtrl()
{
    return m_textCtrl;
}

T100VOID T100EditorFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    SetLabel(L"T100Editor");

    m_editor        = T100NEW T100Editor();

    m_textCtrl      = T100NEW T100TextCtrl();

    m_textCtrl->Create(this);

    m_textCtrl->Show();

    m_editor->SetFrame(this);

    T100FillLayout* layout = T100NEW T100FillLayout();

    SetLayout(layout);

    T100MenuBar*        menuBar         = T100NEW T100MenuBar();
    T100Menu*           fileMenu        = T100NEW T100Menu(menuBar, L"File");
    T100Menu*           editMenu        = T100NEW T100Menu(menuBar, L"Edit");
    T100Menu*           viewMenu        = T100NEW T100Menu(menuBar, L"View");
    T100Menu*           searchMenu      = T100NEW T100Menu(menuBar, L"Search");
    T100Menu*           settingMenu     = T100NEW T100Menu(menuBar, L"Setting");
    T100Menu*           helpMenu        = T100NEW T100Menu(menuBar, L"Help");

    T100MenuItem*       newItem         = T100NEW T100MenuItem(fileMenu, T100MENU_NEW, L"New");
    T100MenuItem*       openItem        = T100NEW T100MenuItem(fileMenu, T100MENU_OPEN, L"Open");
    T100MenuItem*       closeItem       = T100NEW T100MenuItem(fileMenu, T100MENU_CLOSE, L"Close");

    fileMenu->AppendSeparator();

    T100MenuItem*       saveItem        = T100NEW T100MenuItem(fileMenu, T100MENU_SAVE, L"Save");
    T100MenuItem*       saveAsItem      = T100NEW T100MenuItem(fileMenu, T100MENU_SAVE_AS, L"Save as");

    fileMenu->AppendSeparator();

    T100MenuItem*       quitItem        = T100NEW T100MenuItem(fileMenu, T100MENU_QUIT, L"Quit");

    T100MenuItem*       undoItem        = T100NEW T100MenuItem(editMenu, T100MENU_UNDO, L"Undo");
    T100MenuItem*       redoItem        = T100NEW T100MenuItem(editMenu, T100MENU_REDO, L"Redo");

    editMenu->AppendSeparator();

    T100MenuItem*       cutItem         = T100NEW T100MenuItem(editMenu, T100MENU_CUT, L"Cut");
    T100MenuItem*       copyItem        = T100NEW T100MenuItem(editMenu, T100MENU_COPY, L"Copy");
    T100MenuItem*       pasteItem       = T100NEW T100MenuItem(editMenu, T100MENU_PASTE, L"Paste");

    T100MenuItem*       fontItem        = T100NEW T100MenuItem(viewMenu, T100MENU_FONT, L"Font");

    T100MenuItem*       findItem        = T100NEW T100MenuItem(searchMenu, T100MENU_FIND, L"Find");
    T100MenuItem*       replaceItem     = T100NEW T100MenuItem(searchMenu, T100MENU_REPLACE, L"Replace");
    T100MenuItem*       configItem      = T100NEW T100MenuItem(settingMenu, T100MENU_CONFIG, L"Config");
    T100MenuItem*       aboutItem       = T100NEW T100MenuItem(helpMenu, T100MENU_ABOUT, L"About");

    SetMenuBar(menuBar);

    ConnectMenu(T100MENU_NEW,       (T100EVENT_FUNCTION)&OnMenuNew);
    ConnectMenu(T100MENU_OPEN,      (T100EVENT_FUNCTION)&OnMenuOpen);
    ConnectMenu(T100MENU_CLOSE,     (T100EVENT_FUNCTION)&OnMenuClose);
    ConnectMenu(T100MENU_SAVE,      (T100EVENT_FUNCTION)&OnMenuSave);
    ConnectMenu(T100MENU_SAVE_AS,   (T100EVENT_FUNCTION)&OnMenuSaveAs);
    ConnectMenu(T100MENU_QUIT,      (T100EVENT_FUNCTION)&OnMenuQuit);
    ConnectMenu(T100MENU_UNDO,      (T100EVENT_FUNCTION)&OnMenuUndo);
    ConnectMenu(T100MENU_REDO,      (T100EVENT_FUNCTION)&OnMenuRedo);
    ConnectMenu(T100MENU_CUT,       (T100EVENT_FUNCTION)&OnMenuCut);
    ConnectMenu(T100MENU_COPY,      (T100EVENT_FUNCTION)&OnMenuCopy);
    ConnectMenu(T100MENU_PASTE,     (T100EVENT_FUNCTION)&OnMenuPaste);
    ConnectMenu(T100MENU_FONT,      (T100EVENT_FUNCTION)&OnMenuFont);
    ConnectMenu(T100MENU_FIND,      (T100EVENT_FUNCTION)&OnMenuFind);
    ConnectMenu(T100MENU_REPLACE,   (T100EVENT_FUNCTION)&OnMenuReplace);
    ConnectMenu(T100MENU_CONFIG,    (T100EVENT_FUNCTION)&OnMenuConfig);
    ConnectMenu(T100MENU_ABOUT,     (T100EVENT_FUNCTION)&OnMenuAbout);

    Maximize();

    m_editor->New();
}

T100VOID T100EditorFrame::Destroy()
{
    T100SAFE_DELETE(m_editor);
    T100SAFE_DELETE(m_textCtrl);
}

T100VOID T100EditorFrame::SetDirty()
{

}

T100VOID T100EditorFrame::ClearDirty()
{

}

T100VOID T100EditorFrame::SetTitle(T100WSTRING value)
{
    T100WSTRING result  = m_project + L" - " + value;
    SetLabel(result);
}

T100VOID T100EditorFrame::OnMenuNew(T100MenuEvent& event)
{
    m_textCtrl->SetValue(L"");

    m_editor->New();
}

T100VOID T100EditorFrame::OnMenuOpen(T100MenuEvent& event)
{
    m_editor->Open();
}

T100VOID T100EditorFrame::OnMenuClose(T100MenuEvent& event)
{
    m_editor->Close();
}

T100VOID T100EditorFrame::OnMenuSave(T100MenuEvent& event)
{
    m_editor->Save();
}

T100VOID T100EditorFrame::OnMenuSaveAs(T100MenuEvent& event)
{
    m_editor->SaveAs();
}

T100VOID T100EditorFrame::OnMenuQuit(T100MenuEvent& event)
{
    m_editor->Quit();
}

T100VOID T100EditorFrame::OnMenuUndo(T100MenuEvent& event)
{
    m_editor->Undo();
}

T100VOID T100EditorFrame::OnMenuRedo(T100MenuEvent& event)
{
    m_editor->Redo();
}

T100VOID T100EditorFrame::OnMenuCut(T100MenuEvent& event)
{
    m_editor->Cut();
}

T100VOID T100EditorFrame::OnMenuCopy(T100MenuEvent& event)
{
    m_editor->Copy();
}

T100VOID T100EditorFrame::OnMenuPaste(T100MenuEvent& event)
{
    m_editor->Paste();
}

T100VOID T100EditorFrame::OnMenuFont(T100MenuEvent& event)
{
    m_editor->Font();
}

T100VOID T100EditorFrame::OnMenuFind(T100MenuEvent& event)
{
    m_editor->Find();
}

T100VOID T100EditorFrame::OnMenuReplace(T100MenuEvent& event)
{
    m_editor->Replace();
}

T100VOID T100EditorFrame::OnMenuConfig(T100MenuEvent& event)
{
    m_editor->Config();
}

T100VOID T100EditorFrame::OnMenuAbout(T100MenuEvent& event)
{
    m_editor->About();
}
