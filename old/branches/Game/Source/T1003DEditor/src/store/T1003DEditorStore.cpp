#include "T1003DEditorStore.h"

#include "T1003DEditorTaskReadFile.h"

T1003DEditorStore::T1003DEditorStore()
{
    //ctor
}

T1003DEditorStore::~T1003DEditorStore()
{
    //dtor
}

T100BOOL T1003DEditorStore::Open(T100WSTRING filename, T1003DEditorDocument& document)
{
    T1003DEditorTaskReadFile    task;

    task.Read(filename, document);
}

T100BOOL T1003DEditorStore::Save(T100WSTRING filename, T1003DEditorDocument& document)
{

}
