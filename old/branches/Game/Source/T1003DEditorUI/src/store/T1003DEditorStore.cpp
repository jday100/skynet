#include "T1003DEditorStore.h"
#include "library/T100StringTools.h"
#include "game/file/T100File3DF.h"
#include "game/file/T100FileGLTF.h"
#include "game/file/T100FileH3D.h"
#include "game/file/T100FileTools.h"
#include "game/file/T1003DFileReader.h"
#include "game/file/T1003DFileWriter.h"


T1003DEditorStore::T1003DEditorStore() :
    m_settingsStore()
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

    T100File3DF             file3df;
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

    T100File3DF             file3df;
    T1003DFileWriter        writer(filename);

    document->Encode(file3df);

    writer << file3df;
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

    std::wstring    extName;

    extName = T100StringTools::ToLower(T100FileTools::GetFileExtension(filename));

    if(extName == L"gltf"){
        LoadGLTF(filename, document);
    }else if(extName == L"h3d"){
        LoadH3D(filename, document);
    }
    return T100TRUE;
}

T100VOID T1003DEditorStore::LoadGLTF(T100WSTRING& filename, T1003DEditorDocument* document)
{
    T100FileGLTF            gltf(filename);
    T1003DFileReader        reader(filename);

    //reader >> gltf;
    gltf.Load();

    document->Decode(gltf);

    document->m_filename    = filename;
}

T100VOID T1003DEditorStore::LoadH3D(T100WSTRING& filename, T1003DEditorDocument* document)
{
    T100FileH3D             h3d(filename);
    T1003DFileReader        reader(filename);

    //reader >> h3d;
    h3d.Load();

    document->Decode(h3d);

    document->m_filename    = filename;
}

T1003DEditorSettingsStore& T1003DEditorStore::GetSettingsStore()
{
    return m_settingsStore;
}
