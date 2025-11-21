#include "T100FileH3DDecoder.h"

#include "T100DataParser.h"

T100FileH3DDecoder::T100FileH3DDecoder()
{
    //ctor
}

T100FileH3DDecoder::~T100FileH3DDecoder()
{
    //dtor
}

T100VOID T100FileH3DDecoder::Decode(T100FileH3D* file)
{
    T100DataParser          parser(file->m_buffer);


    size_t                          size;
    T100H3D::T100H3D_HEADER*        header;

    //size    = sizeof(T100H3D::T100H3D_HEADER);

    header  = (T100H3D::T100H3D_HEADER*)parser.Get(sizeof(T100H3D::T100H3D_HEADER));

    T100UINT32      meshCount       = header->MeshCount;

    file->m_meshes.resize(meshCount);

    /*
    size    = sizeof(XMVECTOR);
    size    = sizeof(T100DX12BoundingBox);
    size    = sizeof(T100H3D::T100H3D_ATTRIB);
    size    = sizeof(T100H3D::T100H3D_MESH);
    */
    size    = sizeof(T100H3D::T100H3D_MESH) * meshCount;
    memcpy(file->m_meshes.data(), parser.Get(size), size);

    for(T100H3D::T100H3D_MESH&  mesh : file->m_meshes){
        T100UINT count  = mesh.VertexCount;
    }

    T100UINT32      materialCount   = header->MaterialCount;

    file->m_materials.resize(materialCount);

    /*
    size    = sizeof(T100H3D::T100H3D_COLOUR);
    size    = sizeof(T100H3D::T100H3D_MATERIAL);
    */
    size    = sizeof(T100H3D::T100H3D_MATERIAL) * materialCount;
    memcpy(file->m_materials.data(), parser.Get(size), size);

    for(T100H3D::T100H3D_MATERIAL&  material : file->m_materials){
        std::string     name = material.Name;
        int i;
        i = 1;
    }

    T100UINT32      totalSize;

    totalSize   = header->VertexDataByteSize
                    + header->IndexDataByteSize
                    + header->VertexDataByteSizeDepth
                    + header->IndexDataByteSize;

    file->m_dataPtr = (T100BYTE*)malloc(totalSize);
    memcpy(file->m_dataPtr, parser.Get(totalSize), totalSize);

    file->m_vertexDataPtr       = file->m_dataPtr;
    file->m_indexDataPtr        = file->m_dataPtr + header->VertexDataByteSize;
    file->m_vertexDataDepthPtr  = file->m_indexDataPtr + header->IndexDataByteSize;
    file->m_indexDataDepthPtr   = file->m_vertexDataDepthPtr + header->VertexDataByteSizeDepth;
}
