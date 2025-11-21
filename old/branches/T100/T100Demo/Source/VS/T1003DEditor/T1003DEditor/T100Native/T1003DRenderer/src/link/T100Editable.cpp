#include "link/T100Editable.h"

T100Editable::T100Editable() :
    T1003DObject()
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

T100VOID T100Editable::SetEditable(T100BOOL flag)
{
    m_editable  = flag;
}

T100BOOL T100Editable::IsEditable()
{
    return m_editable;
}
