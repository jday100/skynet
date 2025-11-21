#include "store/T1003DEditorStore.h"
#include "3d/T1003DFile3DF.h"
#include "3d/T1003DFileGLTF.h"
#include "3d/T1003DFileReader.h"
#include "3d/T1003DFileWriter.h"

T1003DEditorStore::T1003DEditorStore()
{
    //ctor
}

T1003DEditorStore::~T1003DEditorStore()
{
    //dtor
}

T100BOOL T1003DEditorStore::Open(T100WSTRING& filename, T1003DEditorDocument* document)
{
    if(filename.empty()){
        return T100FALSE;
    }

    T1003DFile3DF           file3df;
    T1003DFileReader        reader(filename);

    reader >> file3df;

    document->Decode(file3df);

    document->m_filename    = filename;

    return T100TRUE;
}

T100BOOL T1003DEditorStore::Save(T1003DEditorDocument* document)
{
    T100WSTRING                 filename;

    filename    = document->m_filename;

    T1003DFile3DF           file3df;
    T1003DFileWriter        writer(filename);

    document->Encode(file3df);

    writer << file3df;

    return T100TRUE;
}

T100BOOL T1003DEditorStore::SaveAs(T100WSTRING& filename, T1003DEditorDocument* document)
{
    document->m_filename    = filename;

    Save(document);
}

T100BOOL T1003DEditorStore::Import(T100WSTRING& filename, T1003DEditorDocument* document)
{
    if(filename.empty()){
        return T100FALSE;
    }

    /*
    T1003DFileGLTF          gltf(filename);
    T1003DFileReader        reader(filename);

    //reader >> gltf;
    gltf.Load();

    document->Decode(gltf);

    document->m_filename    = filename;
    */
    return T100TRUE;
}
