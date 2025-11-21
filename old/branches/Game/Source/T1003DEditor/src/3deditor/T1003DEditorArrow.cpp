#include "T1003DEditorArrow.h"

#include "T100Line.h"
#include "T1003DEditorScene.h"

T1003DEditorArrow::T1003DEditorArrow()
{
    //ctor
    init();
}

T1003DEditorArrow::~T1003DEditorArrow()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorArrow::init()
{
    line        = T100NEW T100Line();
    line1       = T100NEW T100Line();
    line2       = T100NEW T100Line();
    line3       = T100NEW T100Line();

    line->SetRenderType(T100_RENDER_2D);
    line1->SetRenderType(T100_RENDER_2D);
    line2->SetRenderType(T100_RENDER_2D);
    line3->SetRenderType(T100_RENDER_2D);

    line->SetMotionType(T100_MOTION_STAND);
    line1->SetMotionType(T100_MOTION_STAND);
    line2->SetMotionType(T100_MOTION_STAND);
    line3->SetMotionType(T100_MOTION_STAND);

    m_entities.push_back(line);
    m_entities.push_back(line1);
    m_entities.push_back(line2);
    m_entities.push_back(line3);
}

T100VOID T1003DEditorArrow::uninit()
{

}

T100VOID T1003DEditorArrow::Load(T100DX12Scene* scene)
{
    for(T100Entity* entity : m_entities){
        scene->Append(entity);
    }
}

T100VOID T1003DEditorArrow::SetLength(T100FLOAT length)
{
    line->SetTerminus(length, 0, 0);
}

T100VOID T1003DEditorArrow::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    line->SetPosition(x, y, z);
}

T100VOID T1003DEditorArrow::SetPosition(T100Vector3 value)
{
    line->SetPosition(value);
}

T100VOID T1003DEditorArrow::SetRotation(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    line->SetRotation(x, y, z);
}

T100VOID T1003DEditorArrow::SetRotation(T100Vector3 rotation)
{
    line->SetRotation(rotation);
}

T100VOID T1003DEditorArrow::SetColour(T100FLOAT r, T100FLOAT g, T100FLOAT b, T100FLOAT a)
{
    line->SetColour(r, g, b, a);
}

T100VOID T1003DEditorArrow::SetColour(T100Vector4u value)
{
    SetColour(value.RED, value.GREEN, value.BLUE, value.ALPHA);
}
