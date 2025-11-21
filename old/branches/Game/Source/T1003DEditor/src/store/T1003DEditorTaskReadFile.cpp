#include "T1003DEditorTaskReadFile.h"

#include <future>
#include "T100JSON.h"
#include "T1003DFileReader.h"
#include "T100FileGLTFDecoder.h"

T1003DEditorTaskReadFile::T1003DEditorTaskReadFile()
{
    //ctor
}

T1003DEditorTaskReadFile::~T1003DEditorTaskReadFile()
{
    //dtor
}

T100VOID T1003DEditorTaskReadFile::Read(T100WSTRING filename, T1003DEditorDocument& document)
{
    std::future<T100FileGLTF*> task = std::async(std::launch::async, [filename](){
        T100FileGLTF*       gltf        = T100NEW T100FileGLTF(filename);

        gltf->Load();

        return gltf;
    });

    task.wait();

    document.m_gltf = task.get();
}
