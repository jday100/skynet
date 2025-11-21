#include "T1003DEditor.h"

#include <thread>
#include <iostream>

#include "T100Debug.h"

T1003DEditor::T1003DEditor() :
    m_game()
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
}

T100VOID T1003DEditor::uninit()
{
}

T100VOID T1003DEditor::Create(HWND hwnd, UINT width, UINT height)
{
    m_game.Create(hwnd, width, height);
    m_width     = width;
    m_height    = height;
}

T100VOID T1003DEditor::SetSize(UINT width, UINT height)
{
    m_game.SetSize(width, height);
    m_width     = width;
    m_height    = height;
}

T100VOID T1003DEditor::Start()
{
    m_scene     = T100NEW T1003DEditorScene(m_game.GetRenderer());

    m_game.SetScene(m_scene);
    m_game.Start();
}

T100VOID T1003DEditor::Stop()
{
    m_game.Stop();
}

T100VOID T1003DEditor::Append(T100Entity* entity)
{
    m_scene->AppendDynamicsEntity(entity);
}

T100VOID T1003DEditor::Render()
{
    //std::cout << "Render..." << std::endl;
    m_game.Update();
    m_game.Render();

    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

T100VOID T1003DEditor::OnKeyDown(UINT8 key)
{
    //DEBUGPRINT("Key:%u", key);
    switch(key){
    default:
        m_game.Move();
    }
}

T100VOID T1003DEditor::OnKeyUp(UINT8 key)
{

}

T100VOID T1003DEditor::OnMouseMove(T100Vector2u value)
{
    //DEBUGPRINT("X:%u Y:%u", value.X, value.Y);
    T100FLOAT   x;
    T100FLOAT   y;

    x   = value.X - m_width / 2.0f;
    y   = (m_height - value.Y) - m_height / 2.0f;

    T100Vector3     position    = {50* x/m_width, 50*y/m_height, 0};
    //m_scene->m_line.SetPosition(position);

    m_scene->m_city.SetPosition(position);
    m_scene->m_line.SetPosition(position);
}

T100VOID T1003DEditor::OnLeftDown()
{

}

T100VOID T1003DEditor::Clear()
{
    m_scene->Clear();
}
