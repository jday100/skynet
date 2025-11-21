#include "base/T100Object.h"

namespace T100LIBRARY{

T100Object::T100Object() :
    T100Class()
{
    //ctor
}

T100Object::~T100Object()
{
    //dtor
}

T100VOID T100Object::SetLabel(const T100WSTRING& label)
{
    m_label     = label;
}

const T100WSTRING& T100Object::GetLabel()
{
    return m_label;
}

}
