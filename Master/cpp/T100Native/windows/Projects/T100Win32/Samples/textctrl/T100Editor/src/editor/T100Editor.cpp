#include "T100Editor.h"

#include "gui/T100TextCtrl.h"
#include "gui/T100FontDialog.h"
#include "editor/T100EditorFrame.h"
#include "gui/T100OpenFileDialog.h"
#include "gui/T100SaveFileDialog.h"
#include "file/text/T100TextFile.h"
#include "file/text/T100TextFileReader.h"

#include "T100EditorAboutDialog.h"

T100Editor::T100Editor() :
    T100Class()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

T100VOID T100Editor::SetFrame(T100EditorFrame* frame)
{
    m_frame     = frame;
    m_textCtrl  = frame->GetTextCtrl();
    m_frame->SetTitle(L"");
}

T100VOID T100Editor::New()
{
    m_textCtrl->SetValue(L"");
    m_filename.clear();
}

T100VOID T100Editor::Open()
{
    Close();
    New();

    T100OpenFileDialog          dialog;

    T100WSTRING                 filename;

    filename    = dialog.GetFileName();

    if(!filename.empty()){
        T100TextFile        text(filename);

        if(text.IsExists()){
            T100WSTRING             result;
            T100TextFileReader*     reader      = text.GetReader();

            reader->Read(result);

            /*
            if(result.find(L"\r") > 0){
                result.replace(result.find(L"\r"), 1, L"");
            }
            */

            m_textCtrl->SetValue(result);

            m_filename  = filename;
            m_frame->SetTitle(m_filename);
        }
    }
}

T100VOID T100Editor::Close()
{
    if(m_textCtrl->IsModified()){
        Save();
    }

    New();
}

T100VOID T100Editor::Save()
{
    if(m_filename.empty()){
        SaveAs();
    }else{
        T100TextFile        text(m_filename);

        T100WSTRING             result;
        T100TextFileWriter*     writer      = text.GetWriter();

        result  = m_textCtrl->GetValue();
        writer->Write(result);

        T100SAFE_DELETE writer;

    }
}

T100VOID T100Editor::SaveAs()
{
    T100SaveFileDialog          dialog;

    T100WSTRING                 filename;

    filename    = dialog.GetFileName();

    if(filename.empty()){

    }else{
        T100TextFile        text(filename);

        if(text.IsExists()){

        }else{
            T100WSTRING             result;
            T100TextFileWriter*     writer      = text.GetWriter();

            result  = m_textCtrl->GetValue();
            writer->Write(result);

            text.FreeWriter(writer);

            m_filename  = filename;
            m_frame->SetTitle(m_filename);
        }
    }
}

T100VOID T100Editor::Quit()
{
    Close();

    PostQuitMessage(0);
}

T100VOID T100Editor::Undo()
{

}

T100VOID T100Editor::Redo()
{

}

T100VOID T100Editor::Cut()
{
    m_textCtrl->IsModified();

    m_textCtrl->GetSelection();
}

T100VOID T100Editor::Copy()
{

}

T100VOID T100Editor::Paste()
{

}

T100VOID T100Editor::Find()
{

}

T100VOID T100Editor::Replace()
{

}

T100VOID T100Editor::Font()
{
    T100FontDialog      dialog;

    dialog.Create(m_frame);

    T100Font        font;

    font    = dialog.GetFont();

    m_textCtrl->SetFont(font);
}

T100VOID T100Editor::Config()
{

}

T100VOID T100Editor::About()
{
    T100EditorAboutDialog       dialog;

    dialog.Create(m_frame);
    dialog.Show();
}
