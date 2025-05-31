#include "base/T100Object.h"

T100Object::T100Object() :
    T100Class()
{
    //ctor
}

T100Object::T100Object(T100WSTRING label) :
    T100Class(),
    m_label(label)
{
    //ctor
}

T100Object::~T100Object()
{
    //dtor
}

T100VOID T100Object::SetLabel(T100WSTRING label)
{
    m_label     = label;
}

T100WSTRING T100Object::GetLabel()
{
    return m_label;
}
