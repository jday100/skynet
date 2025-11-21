#include "T1003DEditorServe.h"

#include "T1003DEditorGLTFDecoder.h"

T1003DEditorServe::T1003DEditorServe()
{
    //ctor
}

T1003DEditorServe::~T1003DEditorServe()
{
    //dtor
}

T100BOOL T1003DEditorServe::Open(T1003DEditorDocument& document)
{
    T1003DEditorGLTFDecoder         decoder;
    T100ENTITY_VECTOR               entities;

    decoder.Decode(document.m_gltf, entities);
}

T1003DEditorDocument& T1003DEditorServe::GetDocument()
{

}
