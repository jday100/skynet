#include "T100MenuCheckableItem.h"

T100MenuCheckableItem::T100MenuCheckableItem(T100Menu* parent, T100UINT id, T100WSTRING label, T100BOOL checked) :
    T100MenuItem(parent, id, label)
{
    //ctor
    m_checked   = checked;
    init();
}

T100MenuCheckableItem::~T100MenuCheckableItem()
{
    //dtor
    uninit();
}

T100VOID T100MenuCheckableItem::init()
{
}

T100VOID T100MenuCheckableItem::uninit()
{

}

T100BOOL T100MenuCheckableItem::IsChecked()
{
    return m_checked;
}
