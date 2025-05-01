#include "T100MenuItemBase.h"

T100MenuItemBase::T100MenuItemBase() :
    m_font(),
    m_help()
{
    //ctor
    init();
}

T100MenuItemBase::~T100MenuItemBase()
{
    //dtor
    uninit();
}

T100VOID T100MenuItemBase::init()
{
    m_enable    = T100TRUE;
    m_checkable = T100FALSE;
}

T100VOID T100MenuItemBase::uninit()
{

}

T100MENU_ITEM_TYPE T100MenuItemBase::GetMenuItemType()
{
    return m_type;
}

T100VOID T100MenuItemBase::Enable()
{
    m_enable    = T100TRUE;
}

T100VOID T100MenuItemBase::Disable()
{
    m_enable    = T100FALSE;
}

T100BOOL T100MenuItemBase::IsEnabled()
{
    return m_enable;
}

T100VOID T100MenuItemBase::SetFont(T100Font& font)
{
    m_font  = font;
}

T100Font& T100MenuItemBase::GetFont()
{
    return m_font;
}

T100VOID T100MenuItemBase::SetHelp(T100WSTRING& help)
{
    m_help  = help;
}

T100WSTRING& T100MenuItemBase::GetHelp()
{
    return m_help;
}

T100BOOL T100MenuItemBase::IsCheckable()
{
    return m_checkable;
}
