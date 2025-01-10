#include "T1003DEditor.h"

T1003DEditor::T1003DEditor()
{
    //ctor
    init();
}

T1003DEditor::~T1003DEditor()
{
    //dtor
    uninit();
}

T100VOID T1003DEditor::init()
{
    m_dx12  = T100NEW T100DX12Base();
}

T100VOID T1003DEditor::uninit()
{
    T100SAFE_DELETE m_dx12;
}

T100VOID T1003DEditor::Create(HWND hwnd, UINT width, UINT height)
{
    m_dx12->Create(hwnd, width, height);

    m_dx12->Start();
}

T100VOID T1003DEditor::SetSize(UINT width, UINT height)
{
    m_dx12->SetSize(width, height);
}

T100VOID T1003DEditor::Render()
{
    m_dx12->Update();
    m_dx12->Render();
}
