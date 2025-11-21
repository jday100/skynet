#include "T100FileTest.h"

#include <iomanip>
#include <iostream>
#include "T100JSON.h"
#include "T100File3DF.h"
#include "T100FileH3D.h"
#include "T1003DFileReader.h"
#include "T1003DFileWriter.h"
#include "T1003DEditorTaskReadFile.h"

#include "T100FileGLTF.h"

T100FileTest::T100FileTest()
{
    //ctor
}

T100FileTest::~T100FileTest()
{
    //dtor
}

int T100FileTest::test()
{
    int result      = 0;

    if(!result){
        //result = test_gltf();
    }

    if(!result){
        //result = test_3df();
    }

    if(!result){
        result = test_h3d();
    }

    return result;
}

int T100FileTest::test_gltf()
{
    T100WSTRING             file        = L"./resources/ModelViewer/Sponza/pbr/sponza2.gltf";
    T1003DFileReader        reader(file, T1003DFILE_GLTF);
    T100JSON                result;

    reader >> result;

    //std::cout << std::setw(4) <<  result.m_json;

    T100FileGLTF            gltf(file);

    gltf.Load();

    return 0;
}

int T100FileTest::test_3df()
{
    T100WSTRING         file        = L"./build/file_test.3df";
    T100File3DF         file3df;
    T1003DFileWriter    writer(file);

    writer << file3df;

    return 0;
}

int T100FileTest::test_h3d()
{
    T100WSTRING             file        = L"./resources/ModelViewer/Sponza/sponza.h3d";
    //T1003DFileReader        reader(file, T1003DFILE_H3D);
    T100FileH3D             h3d(file);

    h3d.Load();

    return 0;
}

int T100FileTest::json_test()
{
    T100WSTRING             file        = L"./build/file_test.3df";
    T1003DFileReader        reader(file, T1003DFILE_3DF);
    T1003DFileWriter        writer(file, T1003DFILE_3DF);
    T100JSON                json;
    T100JSON                result;

    json    = {{"name","json"}};

    writer << json;
    reader >> result;

    if(json["name"] == result["name"]){
        return 0;
    }

    return -1;
}
