#include "T100Cursor.h"

T100Cursor::T100Cursor() :
    T100Class()
{
    //ctor
}

T100Cursor::~T100Cursor()
{
    //dtor
}

HCURSOR T100Cursor::GetHCURSOR()
{
    return m_cursor;
}
