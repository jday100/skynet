#include "T100IDEStoreEditor.h"

#include "T100EditorStore.h"


T100IDEStoreEditor::T100IDEStoreEditor(T100IDEStore* store)
    :T100IDEStoreBase(store)
{
    //ctor
}

T100IDEStoreEditor::~T100IDEStoreEditor()
{
    //dtor
}

T100BOOL T100IDEStoreEditor::open(T100STDSTRING file, T100EditorData* data)
{
    T100BOOL            result;
    T100EditorStore     store;

    result = store.getText()->load(file, data);

    if(result){
        return T100TRUE;
    }

    return T100FALSE;
}
