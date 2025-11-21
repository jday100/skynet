#ifndef T100FILEGLTF_H
#define T100FILEGLTF_H

#include <vector>
#include "T100Common.h"
#include "common/T100EntityCommon.h"
#include "game/file/T100File.h"

namespace GLTF
{
    struct      GLTFBufferView
    {
        T100UINT32          Buffer;
        T100UINT32          ByteLength;
        T100UINT32          ByteOffset;
        T100UINT16          ByteStride;
        T100BOOL            ElementArrayBuffer;
    };

    struct      GLTFAccessor
    {
        enum
        {
            kByte,
            kUnsignedByte,
            kShort,
            kUnsignedShort,
            kSignedInt,
            kUnsignedInt,
            kFloat
        };

        enum
        {
            kScalar,
            kVec2,
            kVec3,
            kVec4,
            kMat2,
            kMat3,
            kMat4
        };
        T100BYTE*       DataPtr;
        T100FILE_DATA   Buffer;
        T100UINT32      Stride;
        T100UINT32      Count;
        T100UINT16      ComponentType;
        T100UINT16      Type;
    };

    struct GLTFImage
    {
        T100STRING      Path;
    };

    struct GLTFSampler
    {
        T100D3D12_FILTER                    Filter;
        T100D3D12_TEXTURE_ADDRESS_MODE      WrapS;
        T100D3D12_TEXTURE_ADDRESS_MODE      WrapT;
    };

    struct GLTFTexture
    {
        GLTFImage*          Source;
        GLTFSampler*        Sampler;
    };

    struct GLTFMaterial
    {
        union
        {
            struct
            {
                T100FLOAT       BaseColorFactor[4];
                T100FLOAT       MetallicFactor;
                T100FLOAT       RoughnessFactor;
            };
        };
        union
        {
            T100UINT32          Flags;
            struct
            {
                T100UINT32      BaseColorUV         : 1;
                T100UINT32      MetallicRoughnessUV : 1;
                T100UINT32      OcclusionUV         : 1;
                T100UINT32      EmissiveUV          : 1;
                T100UINT32      NormalUV            : 1;
                T100UINT32      TwoSided            : 1;
                T100UINT32      AlphaTest           : 1;
                T100UINT32      AlphaBlend          : 1;
                T100UINT32      _pad                : 8;
                T100UINT32      AlphaCutoff         : 16;
            };
        };
        T100FLOAT               EmissiveFactor[3];
        T100FLOAT               NormalTextureScale;
        enum
        {
            kBaseColor,
            kMetallicRoughness,
            kOcclusion,
            kEmissive,
            kNormal,
            kNumTextures
        };
        GLTFTexture*            Textures[kNumTextures];
        T100UINT32              Index;
    };

    struct GLTFPrimitive
    {
        enum eAttribType
        {
            kPosition,
            kNormal,
            kTangent,
            kTexcoord0,
            kTexcoord1,
            kColor0,
            kJoints0,
            kWeights0,
            kNumAttribs
        };
        GLTFAccessor*           Attributes[kNumAttribs];
        GLTFAccessor*           Indices;
        GLTFMaterial*           Material;
        T100UINT16              AttribMask;
        T100UINT16              Mode;
        __declspec(align(16))   T100FLOAT       MinPos[3];
        __declspec(align(16))   T100FLOAT       MaxPos[3];
        T100UINT32              MinIndex;
        T100UINT32              MaxIndex;
    };

    struct GLTFMesh
    {
        std::vector<GLTFPrimitive>      Primitives;
        T100INT32                       Skin;
    };

    struct GLTFCamera
    {
        enum eType
        {
            kPerspective,
            kOrthographic
        }Type;
        union
        {
            struct
            {
                T100FLOAT           AspectRatio;
                T100FLOAT           Yfov;
            };
            struct
            {
                T100FLOAT           xMag;
                T100FLOAT           yMag;
            };
        };
        T100FLOAT           zNear;
        T100FLOAT           zFar;
    };

    struct GLTFNode
    {
        union
        {
            T100UINT8       Flags;
            struct
            {
                T100BOOL    PointsToCamera          : 1;
                T100BOOL    HasMatrix               : 1;
                T100BOOL    SkeletonRoot            : 1;
            };
        };
        union
        {
            GLTFMesh*       Mesh;
            GLTFCamera*     Camera;
        };
        std::vector<GLTFNode*>          Children;
        union
        {
            __declspec(align(16))       T100FLOAT       Matrix[16];
            struct
            {
                __declspec(align(16))   T100FLOAT       Scale[3];
                __declspec(align(16))   T100FLOAT       Rotation[4];
                __declspec(align(16))   T100FLOAT       Translation[3];
            };
        };
        T100INT32           LinearIndex;
    };

    struct GLTFSkin
    {
        GLTFAccessor*       InverseBindMatrices;
        GLTFNode*           Skeleton;
        std::vector<GLTFNode*>          Joints;
    };

    struct GLTFScene
    {
        std::vector<GLTFNode*>          Nodes;
    };

    struct GLTFAnimSampler
    {
        GLTFAccessor*           Input;
        GLTFAccessor*           Output;
        enum eInterpolation
        {
            kLinear,
            kStep,
            kCatmullRomSpline,
            kCubicSpline
        }Interpolation;
    };

    struct GLTFAnimChannel
    {
        GLTFAnimSampler*        Sampler;
        GLTFNode*               Target;
        enum ePath
        {
            kTranslation,
            kRotation,
            kScale,
            kWeights
        }Path;
    };

    struct GLTFAnimation
    {
        std::vector<GLTFAnimChannel>        Channels;
        std::vector<GLTFAnimSampler>        Samplers;
    };

}

using namespace GLTF;

class T100FileGLTF
{
    friend class T100FileGLTFDecoder;
    friend class T1003DEditorDocument;
    public:
        T100FileGLTF(T100WSTRING);
        virtual ~T100FileGLTF();

        T100VOID                        Load();

    protected:
        T100WSTRING                     m_filename;
        std::wstring                    m_basePath;

        GLTFScene*                      m_scene;
        std::vector<GLTFScene>          m_scenes;
        std::vector<GLTFNode>           m_nodes;
        std::vector<GLTFCamera>         m_cameras;
        std::vector<GLTFMesh>           m_meshes;
        std::vector<GLTFImage>          m_images;
        std::vector<GLTFSampler>        m_samplers;
        std::vector<GLTFTexture>        m_textures;
        std::vector<GLTFAccessor>       m_accessors;
        std::vector<GLTFSkin>           m_skins;
        std::vector<GLTFMaterial>       m_materials;
        std::vector<T100FILE_DATA>      m_buffers;
        std::vector<GLTFBufferView>     m_bufferViews;
        std::vector<GLTFAnimation>      m_animations;

    private:
};

#endif // T100FILEGLTF_H
