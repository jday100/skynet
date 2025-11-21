#ifndef T100FILEGLTFDECODER_H
#define T100FILEGLTFDECODER_H

#include "T100File.h"
#include "T100JSON.h"
#include "T100FileGLTF.h"


class T100FileGLTFDecoder
{
    public:
        T100FileGLTFDecoder();
        virtual ~T100FileGLTFDecoder();

        T100VOID            Decode(T100JSON&, T100FileGLTF*);

    protected:
        T100VOID            DecodeBuffers(JSON&, T100BYTE*, T100FileGLTF*);
        T100VOID            DecodeBufferViews(JSON&, T100FileGLTF*);
        T100VOID            DecodeAccessors(JSON&, T100FileGLTF*);
        T100VOID            DecodeMaterials(JSON&, T100FileGLTF*);
        T100VOID            DecodeTextures(JSON&, T100FileGLTF*);
        T100VOID            DecodeSamplers(JSON&, T100FileGLTF*);
        T100VOID            DecodeImages(JSON&, T100FileGLTF*);
        T100VOID            DecodeSkins(JSON&, T100FileGLTF*);
        T100VOID            DecodeMeshes(JSON&, JSON&, T100FileGLTF*);
        T100VOID            DecodeNodes(JSON&, T100FileGLTF*);
        T100VOID            DecodeAnimations(JSON&, T100FileGLTF*);
        T100VOID            DecodeCameras(JSON&, T100FileGLTF*);
        T100VOID            DecodeScenes(JSON&, T100FileGLTF*);

    private:
        T100UINT16                                      TypeToEnum( const char type[] );
        T100UINT32                                      floatToHalf(T100FLOAT);
        T100VOID                                        ReadFloats( JSON& list, T100FLOAT flt_array[] );
        T100UINT32                                      ReadTextureInfo( JSON& info_json, GLTFTexture* &info, T100FileGLTF* );
        T100D3D12_TEXTURE_ADDRESS_MODE                  GLtoD3DTextureAddressMode( T100INT32 glWrapMode );
        T100VOID                                        FindAttribute( T100FileGLTF*, GLTFPrimitive& prim, JSON& attributes, GLTFPrimitive::eAttribType type, const std::string& name );
};

#endif // T100FILEGLTFDECODER_H
