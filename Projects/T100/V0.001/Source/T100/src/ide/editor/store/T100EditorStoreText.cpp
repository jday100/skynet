#include "T100EditorStoreText.h"

#include "T100EditorReaderText.h"


T100EditorStoreText::T100EditorStoreText(T100EditorStore* store)
    :T100EditorStoreBase(store)
{
    //ctor
}

T100EditorStoreText::~T100EditorStoreText()
{
    //dtor
}

T100BOOL T100EditorStoreText::load(T100STDSTRING file, T100EditorData*& data)
{
    return T100EditorReaderText::load(file, data->m_data);
}

T100BOOL T100EditorStoreText::save(T100STDSTRING file, T100EditorData* data)
{
    return T100FALSE;
}
