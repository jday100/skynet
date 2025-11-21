#include "T100Editable.h"

T100Editable::T100Editable() :
    T100Entity()
{
    //ctor
    init();
}

T100Editable::~T100Editable()
{
    //dtor
    uninit();
}

T100VOID T100Editable::init()
{
    m_editable  = T100FALSE;
}

T100VOID T100Editable::uninit()
{

}

T100Entity* T100Editable::GetSelection()
{
    return m_selection;
}

T100VOID T100Editable::SetEditable(T100BOOL flag)
{
    m_editable  = flag;
    if(!flag){
        if(m_selection){
            m_selection->SetVisible(T100FALSE);
        }
    }
}

T100BOOL T100Editable::IsEditable()
{
    return m_editable;
}


T100VOID T100Editable::SetPosition(T100FLOAT x, T100FLOAT y, T100FLOAT z)
{
    T100Entity::SetPosition(x, y, z);
    if(m_editable){
        m_selection->SetPosition(x, y, z);
    }
}

T100VOID T100Editable::SetPosition(T100Vector3 value)
{
    T100Entity::SetPosition(value);
    if(m_editable){
        m_selection->SetPosition(value);
    }
}
