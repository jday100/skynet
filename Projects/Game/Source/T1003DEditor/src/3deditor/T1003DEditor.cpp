#include "T1003DEditor.h"

#include <thread>
/*
#include "T100DX12.h"
#include "T100DX12Editor.h"
#include "T100DX12Entities.h"
#include "T100DX12Line.h"
#include "T100DX12Triangle.h"
#include "T100DX12Renderer.h"
#include "T100DX12Bundles.h"

#include "T100DXBase.h"
#include "T100DXBundles.h"
#include "T100DXEntity.h"
*/

#include "T100DX12Bundles.h"
#include "T100DX12Entity.h"

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
    m_dx12  = T100NEW T100DX12Entity();
}

T100VOID T1003DEditor::uninit()
{
    T100SAFE_DELETE m_dx12;
}

T100VOID T1003DEditor::Create(HWND hwnd, UINT width, UINT height)
{
    m_dx12->Create(hwnd, width, height);
    m_width     = width;
    m_height    = height;
    m_dx12->Start();
}

T100VOID T1003DEditor::SetSize(UINT width, UINT height)
{
    m_dx12->SetSize(width, height);
    m_width     = width;
    m_height    = height;
}

T100VOID T1003DEditor::Append(T100Entity* entity)
{
    //m_dx12->Append(entity);
    //m_dx12->Update();
}

T100VOID T1003DEditor::Render()
{
    m_dx12->Update();
    m_dx12->Render();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    UINT    size    = m_width * m_height *4;
    UINT8*  buffer  = T100NEW UINT8[size];
    //m_dx12->GetImage(&buffer);
}

T100VOID T1003DEditor::OnKeyDown(UINT8 key)
{
    m_dx12->OnKeyDown(key);
}

T100VOID T1003DEditor::OnKeyUp(UINT8 key)
{
    m_dx12->OnKeyUp(key);
}
