#include "T100EditorStore.h"

T100EditorStore::T100EditorStore()
{
    //ctor
    create();
}

T100EditorStore::~T100EditorStore()
{
    //dtor
    destroy();
}

T100VOID T100EditorStore::create()
{
    m_text      = T100NEW T100EditorStoreText(this);
    m_binary    = T100NEW T100EditorStoreBinary(this);
}

T100VOID T100EditorStore::destroy()
{

}

T100EditorStoreText* T100EditorStore::getText()
{
    return m_text;
}

T100EditorStoreBinary* T100EditorStore::getBinary()
{
    return m_binary;
}
