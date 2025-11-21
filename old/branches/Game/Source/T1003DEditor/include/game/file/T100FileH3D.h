#ifndef T100FILEH3D_H
#define T100FILEH3D_H

//#pragma pack(16)

#include <vector>
#include "T100Common.h"
#include "T100File.h"
#include "data/T100DX12Colour.h"
#include "collision/T100DX12BoundingBox.h"

namespace T100H3D{

enum
{
    attrib_mask_0 = (1 << 0),
    attrib_mask_1 = (1 << 1),
    attrib_mask_2 = (1 << 2),
    attrib_mask_3 = (1 << 3),
    attrib_mask_4 = (1 << 4),
    attrib_mask_5 = (1 << 5),
    attrib_mask_6 = (1 << 6),
    attrib_mask_7 = (1 << 7),
    attrib_mask_8 = (1 << 8),
    attrib_mask_9 = (1 << 9),
    attrib_mask_10 = (1 << 10),
    attrib_mask_11 = (1 << 11),
    attrib_mask_12 = (1 << 12),
    attrib_mask_13 = (1 << 13),
    attrib_mask_14 = (1 << 14),
    attrib_mask_15 = (1 << 15),

    // friendly name aliases
    attrib_mask_position = attrib_mask_0,
    attrib_mask_texcoord0 = attrib_mask_1,
    attrib_mask_normal = attrib_mask_2,
    attrib_mask_tangent = attrib_mask_3,
    attrib_mask_bitangent = attrib_mask_4,
};

enum
{
    attrib_0 = 0,
    attrib_1 = 1,
    attrib_2 = 2,
    attrib_3 = 3,
    attrib_4 = 4,
    attrib_5 = 5,
    attrib_6 = 6,
    attrib_7 = 7,
    attrib_8 = 8,
    attrib_9 = 9,
    attrib_10 = 10,
    attrib_11 = 11,
    attrib_12 = 12,
    attrib_13 = 13,
    attrib_14 = 14,
    attrib_15 = 15,

    // friendly name aliases
    attrib_position = attrib_0,
    attrib_texcoord0 = attrib_1,
    attrib_normal = attrib_2,
    attrib_tangent = attrib_3,
    attrib_bitangent = attrib_4,

    maxAttribs = 16
};

enum
{
    attrib_format_none = 0,
    attrib_format_ubyte,
    attrib_format_byte,
    attrib_format_ushort,
    attrib_format_short,
    attrib_format_float,

    attrib_formats
};

typedef struct __attribute__((aligned(16))) T100H3D_HEADER{
    T100UINT32                  MeshCount;
    T100UINT32                  MaterialCount;
    T100UINT32                  VertexDataByteSize;
    T100UINT32                  IndexDataByteSize;
    T100UINT32                  VertexDataByteSizeDepth;
    //T100DX12BoundingBox         BoundingBox;
    XMVECTOR                    Min;
    XMVECTOR                    Max;
}T100H3D_HEADER;

typedef struct T100H3D_ATTRIB{
    T100UINT16                  Offset;
    T100UINT16                  Normalized;
    T100UINT16                  Components;
    T100UINT16                  Format;
}T100H3D_ATTRIB;

typedef struct __attribute__((aligned(8))) T100H3D_MESH{
    //T100DX12BoundingBox         BoundingBox;
    XMVECTOR                    Min;
    XMVECTOR                    Max;
    T100UINT32                  MaterialIndex;
    T100UINT32                  AttrisEnabled;
    T100UINT32                  AttribsEnabledDepth;
    T100UINT32                  VertexStride;
    T100UINT32                  VertexStrideDepth;
    T100H3D_ATTRIB              Attrib[T100H3D::maxAttribs];
    T100H3D_ATTRIB              AttribDepth[T100H3D::maxAttribs];

    T100UINT32                  VertexDataByteOffset;
    T100UINT32                  VertexCount;
    T100UINT32                  IndexDataByteOffset;
    T100UINT32                  IndexCount;
    T100UINT32                  VertexDataByteOffsetDepth;
    T100UINT32                  VertexCountDepth;
}T100H3D_MESH;

typedef struct T100H3D_COLOUR{
    XMVECTORF32     COLOUR;
}T100H3D_COLOUR;

typedef struct __attribute__((aligned(16))) T100H3D_MATERIAL{
    T100H3D_COLOUR              Diffuse;
    T100H3D_COLOUR              Specular;
    T100H3D_COLOUR              Ambient;
    T100H3D_COLOUR              Emissive;
    T100H3D_COLOUR              Transparent;
    T100FLOAT                   Opacity;
    T100FLOAT                   Shininess;
    T100FLOAT                   SpecularStrength;

    enum{maxTexPath = 128};
    enum{texCount = 6};

    T100CHAR                    TexDiffusePath[maxTexPath];
    T100CHAR                    TexSpecularPath[maxTexPath];
    T100CHAR                    TexEmissivePath[maxTexPath];
    T100CHAR                    TexNormalPath[maxTexPath];
    T100CHAR                    TexLightmapPath[maxTexPath];
    T100CHAR                    TexReflectionPath[maxTexPath];

    enum{maxMaterialName = 128};

    T100CHAR                    Name[maxMaterialName];
}T100H3D_MATERIAL;

}

class T100FileH3D
{
    friend class T100FileH3DDecoder;
    friend class T1003DEditorDocument;
    public:
        T100FileH3D(T100WSTRING);
        virtual ~T100FileH3D();

        T100VOID            Load();

    protected:
        T100WSTRING         m_filename;
        T100FILE_DATA       m_buffer;

        T100BYTE*           m_dataPtr               = T100NULL;
        T100BYTE*           m_vertexDataPtr         = T100NULL;
        T100BYTE*           m_indexDataPtr          = T100NULL;
        T100BYTE*           m_vertexDataDepthPtr    = T100NULL;
        T100BYTE*           m_indexDataDepthPtr     = T100NULL;

        std::vector<T100H3D::T100H3D_MESH>          m_meshes;
        std::vector<T100H3D::T100H3D_MATERIAL>      m_materials;

    private:
};

#endif // T100FILEH3D_H
