#include "T100Editor.h"

T100Editor::T100Editor()
{
    //ctor
}

T100Editor::~T100Editor()
{
    //dtor
}

void T100Editor::Create()
{
    m_value     = new int();
}

void T100Editor::Message()
{
    *m_value    = 1;
}
