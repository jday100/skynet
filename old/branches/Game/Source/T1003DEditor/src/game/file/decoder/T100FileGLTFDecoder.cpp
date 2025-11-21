#include "T100FileGLTFDecoder.h"

#include "T100Debug.h"
#include "T100VectorTools.h"
#include "T100FileGLTF.h"
#include "T100FileTools.h"

using namespace GLTF;

T100FileGLTFDecoder::T100FileGLTFDecoder()
{
    //ctor
}

T100FileGLTFDecoder::~T100FileGLTFDecoder()
{
    //dtor
}

T100VOID T100FileGLTFDecoder::Decode(T100JSON& json, T100FileGLTF* gltf)
{
    if(!json.IsObject()){
        return;
    }

    T100BYTE*       chunk        = T100NULL;

    if(json.Find("buffers") != json.End()){
        DecodeBuffers(json.At("buffers"), chunk, gltf);
    }
    if(json.Find("bufferViews") != json.End()){
        DecodeBufferViews(json.At("bufferViews"), gltf);
    }
    if(json.Find("accessors") != json.End()){
        DecodeAccessors(json.At("accessors"), gltf);
    }
    if(json.Find("images") != json.End()){
        DecodeImages(json.At("images"), gltf);
    }
    if(json.Find("samplers") != json.End()){
        DecodeSamplers(json.At("samplers"), gltf);
    }
    if(json.Find("textures") != json.End()){
        DecodeTextures(json.At("textures"), gltf);
    }
    if(json.Find("materials") != json.End()){
        DecodeMaterials(json.At("materials"), gltf);
    }
    if(json.Find("meshes") != json.End()){
        DecodeMeshes(json.At("meshes"), json.At("accessors"), gltf);
    }
    if(json.Find("cameras") != json.End()){
        DecodeCameras(json.At("cameras"), gltf);
    }
    if(json.Find("skins") != json.End()){
        //
    }
    if(json.Find("nodes") != json.End()){
        DecodeNodes(json.At("nodes"), gltf);
    }
    if(json.Find("scenes") != json.End()){
        DecodeScenes(json.At("scenes"), gltf);
    }
    if(json.Find("animations") != json.End()){
        DecodeAnimations(json.At("animations"), gltf);
    }
}

T100VOID T100FileGLTFDecoder::DecodeBuffers(JSON& json, T100BYTE* chunk, T100FileGLTF* gltf)
{
    gltf->m_buffers.reserve(json.size());

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        JSON&   thisBuffer      = it.value();

        if(thisBuffer.find("uri") != thisBuffer.end())
        {
            const std::string&      uri = thisBuffer.at("uri");

            std::wstring filepath   = gltf->m_basePath + std::wstring(uri.begin(), uri.end());

            T100FILE_DATA    data    = T100FileTools::ReadBinaryFile(filepath);

            gltf->m_buffers.push_back(data);

            //T100BYTE*   data    = ReadFile(filepath);
            //gltf->m_buffers.push_back(data);
        }
        else
        {
            ASSERT(it == json.begin(), "Only the 1st buffer allowed to be internal");
            ASSERT(chunk, "GLB chunk1 missing data or not a GLB file");
            //gltf->m_buffers.push_back(chunk);
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeBufferViews(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_bufferViews.reserve(json.size());

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFBufferView          bufferView;

        JSON&   thisBufferView      = it.value();

        bufferView.Buffer       = thisBufferView.at("buffer");
        bufferView.ByteLength   = thisBufferView.at("byteLength");
        bufferView.ByteOffset   = 0;
        bufferView.ByteStride   = 0;
        bufferView.ElementArrayBuffer       = T100FALSE;

        if(thisBufferView.find("byteOffset") != thisBufferView.end()){
            bufferView.ByteOffset   = thisBufferView.at("byteOffset");
        }
        if(thisBufferView.find("byteStride") != thisBufferView.end()){
            bufferView.ByteStride   = thisBufferView.at("byteStride");
        }
        if(thisBufferView.find("target") != thisBufferView.end() && thisBufferView.at("target") == 34963){
            bufferView.ElementArrayBuffer   = T100TRUE;
        }
        gltf->m_bufferViews.push_back(bufferView);
    }
}

T100VOID T100FileGLTFDecoder::DecodeAccessors(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_accessors.reserve(json.size());

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFAccessor        accessor;
        JSON&       thisAccessor        = it.value();

        GLTFBufferView&     bufferView  = gltf->m_bufferViews[thisAccessor.at("bufferView")];

        accessor.Buffer     = gltf->m_buffers[bufferView.Buffer];
        accessor.DataPtr    = accessor.Buffer.Data + bufferView.ByteOffset;

        //accessor.DataPtr    = gltf->m_buffers[bufferView.Buffer]->data() + bufferView.ByteOffset;
        accessor.Stride     = bufferView.ByteStride;

        if(thisAccessor.find("byteOffset") != thisAccessor.end()){
            accessor.DataPtr += thisAccessor.at("byteOffset").get<int>();
        }

        accessor.Count      = thisAccessor.at("count");
        accessor.ComponentType  = thisAccessor.at("componentType").get<T100UINT16>() - 5120;

        T100CHAR        type[8];

        strcpy_s(type, thisAccessor.at("type").get<std::string>().c_str());

        accessor.Type       = TypeToEnum(type);

        gltf->m_accessors.push_back(accessor);
    }
}

T100VOID T100FileGLTFDecoder::DecodeImages(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_images.resize(json.size());

    T100UINT32      imageIndex      = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        JSON&   thisImage       = it.value();
        if(thisImage.find("uri") != thisImage.end())
        {
            gltf->m_images[imageIndex++].Path = thisImage.at("uri").get<std::string>();
        }
        else if(thisImage.find("bufferView") != thisImage.end())
        {
            Utility::Printf("GLB image at buffer view %d with mime type %s\n", thisImage.at("bufferView").get<uint32_t>(), thisImage.at("mimeType").get<std::string>().c_str());
        }
        else
        {
            ASSERT(0);
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeSamplers(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_samplers.resize(json.size());

    T100UINT32      samplerIndex        = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        JSON&   thisSampler     = it.value();

        GLTFSampler&    sampler = gltf->m_samplers[samplerIndex++];

        sampler.Filter  = T100D3D12_FILTER_ANISOTROPIC;
        sampler.WrapS   = T100D3D12_TEXTURE_ADDRESS_MODE_WRAP;
        sampler.WrapT   = T100D3D12_TEXTURE_ADDRESS_MODE_WRAP;

        if(thisSampler.find("wrapS") != thisSampler.end()){
            sampler.WrapS   = GLtoD3DTextureAddressMode(thisSampler.at("wrapS"));
        }
        if(thisSampler.find("wrapT") != thisSampler.end()){
            sampler.WrapT   = GLtoD3DTextureAddressMode(thisSampler.at("wrapT"));
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeTextures(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_textures.resize(json.size());

    T100UINT32      texIndex        = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFTexture&    texture     = gltf->m_textures[texIndex++];

        JSON&   thisTexture         = it.value();

        texture.Source      = T100NULL;
        texture.Sampler     = T100NULL;

        if(thisTexture.find("source") != thisTexture.end()){
            texture.Source  = &gltf->m_images[thisTexture.at("source")];
        }
        if(thisTexture.find("sampler") != thisTexture.end()){
            texture.Sampler = &gltf->m_samplers[thisTexture.at("sampler")];
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeMaterials(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_materials.reserve(json.size());

    T100UINT32      materialIndex       = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFMaterial        material;
        JSON&       thisMaterial        = it.value();

        material.Index                  = materialIndex++;
        material.Flags                  = 0;
        material.AlphaCutoff            = floatToHalf(0.5f);
        material.NormalTextureScale     = 1.0f;

        if(thisMaterial.find("alphaMode") != thisMaterial.end())
        {
            std::string alphaMode   = thisMaterial.at("alphaMode");
            if(alphaMode == "BLEND"){
                material.AlphaBlend = T100TRUE;
            }
            else if(alphaMode == "MASK")
            {
                material.AlphaTest  = T100TRUE;
            }
        }

        if(thisMaterial.find("alphaCutoff") != thisMaterial.end())
        {
            material.AlphaCutoff    = floatToHalf(thisMaterial.at("alphaCutoff"));
        }

        if(thisMaterial.find("pbrMetallicRoughness") != thisMaterial.end())
        {
            JSON&       metallicRoughness   = thisMaterial.at("pbrMetallicRoughness");

            material.BaseColorFactor[0] = 1.0f;
            material.BaseColorFactor[1] = 1.0f;
            material.BaseColorFactor[2] = 1.0f;
            material.BaseColorFactor[3] = 1.0f;
            material.MetallicFactor     = 1.0f;
            material.RoughnessFactor    = 1.0f;

            for(T100UINT32 i = 0; i < GLTFMaterial::kNumTextures; ++i)
            {
                material.Textures[i]    = T100NULL;
            }

            if(metallicRoughness.find("baseColorFactor") != metallicRoughness.end())
            {
                ReadFloats(metallicRoughness.at("baseColorFactor"), material.BaseColorFactor);
            }
            if(metallicRoughness.find("metallicFactor") != metallicRoughness.end())
            {
                material.MetallicFactor = metallicRoughness.at("metallicFactor");
            }
            if(metallicRoughness.find("roughnessFactor") != metallicRoughness.end())
            {
                material.RoughnessFactor    = metallicRoughness.at("roughnessFactor");
            }
            if(metallicRoughness.find("baseColorTexture") != metallicRoughness.end())
            {
                material.BaseColorUV    = ReadTextureInfo(metallicRoughness.at("baseColorTexture"),
                    material.Textures[GLTFMaterial::kBaseColor], gltf);
            }
            if(metallicRoughness.find("metallicRoughnessTexture") != metallicRoughness.end())
            {
                material.MetallicRoughnessUV    = ReadTextureInfo(metallicRoughness.at("metallicRoughnessTexture"),
                    material.Textures[GLTFMaterial::kMetallicRoughness], gltf);
            }
        }

        if(thisMaterial.find("doubleSided") != thisMaterial.end())
        {
            material.TwoSided   = thisMaterial.at("doubleSided");
        }
        if(thisMaterial.find("normalTextureScale") != thisMaterial.end())
        {
            material.NormalTextureScale = thisMaterial.at("normalTextureScale");
        }
        if(thisMaterial.find("emissiveFactor") != thisMaterial.end())
        {
            ReadFloats(thisMaterial.at("emissiveFactor"), material.EmissiveFactor);
        }
        if(thisMaterial.find("occlusionTexture") != thisMaterial.end())
        {
            material.OcclusionUV    = ReadTextureInfo(thisMaterial.at("occlusionTexture"),
                material.Textures[GLTFMaterial::kOcclusion], gltf);
        }
        if(thisMaterial.find("emissiveTexture") != thisMaterial.end())
        {
            material.EmissiveUV     = ReadTextureInfo(thisMaterial.at("emissiveTexture"),
                material.Textures[GLTFMaterial::kEmissive], gltf);
        }
        if(thisMaterial.find("normalTexture") != thisMaterial.end())
        {
            material.NormalUV   = ReadTextureInfo(thisMaterial.at("normalTexture"),
                material.Textures[GLTFMaterial::kNormal], gltf);
        }

        gltf->m_materials.push_back(material);
    }
}

T100VOID T100FileGLTFDecoder::DecodeMeshes(JSON& json, JSON& accessors, T100FileGLTF* gltf)
{
    gltf->m_meshes.resize(json.size());

    T100UINT32      meshIndex    = 0;

    for(JSON::iterator meshIt = json.begin(); meshIt != json.end(); ++meshIt, ++meshIndex)
    {
        JSON&       thisMesh        = meshIt.value();
        JSON&       primitives      = thisMesh.at("primitives");

        gltf->m_meshes[meshIndex].Primitives.resize(primitives.size());
        gltf->m_meshes[meshIndex].Skin  = -1;

        T100UINT32      subMeshIndex        = 0;
        for(JSON::iterator primIt = primitives.begin(); primIt != primitives.end(); ++primIt, ++subMeshIndex)
        {
            GLTFPrimitive&  prim    = gltf->m_meshes[meshIndex].Primitives[subMeshIndex];
            JSON&       thisPrim        = primIt.value();

            prim.AttribMask     = 0;
            JSON&   attributes  = thisPrim.at("attributes");

            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kPosition, "POSITION");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kNormal, "NORMAL");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kTangent, "TANGENT");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kTexcoord0, "TEXCOORD_0");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kTexcoord1, "TEXCOORD_1");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kColor0, "COLOR_0");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kJoints0, "JOINTS_0");
            FindAttribute(gltf, prim, attributes, GLTFPrimitive::kWeights0, "WEIGHTS_0");

            JSON&   positionAccessor    = accessors[attributes.at("POSITION").get<T100UINT32>()];
            ReadFloats(positionAccessor.at("min"), prim.MinPos);
            ReadFloats(positionAccessor.at("max"), prim.MaxPos);

            prim.Mode       = T100D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
            prim.Indices    = T100NULL;
            prim.Material   = T100NULL;
            prim.MinIndex   = 0;
            prim.MaxIndex   = 0;
            prim.Mode       = 4;

            if(thisPrim.find("model") != thisPrim.end())
            {
                prim.Mode       = thisPrim.at("mode");
            }
            if(thisPrim.find("indices") != thisPrim.end())
            {
                T100UINT32  accessorIndex   = thisPrim.at("indices");
                JSON&       indicesAccessor = accessors[accessorIndex];
                prim.Indices    = &gltf->m_accessors[accessorIndex];
                if(indicesAccessor.find("max") != indicesAccessor.end())
                {
                    prim.MaxIndex   = indicesAccessor.at("max")[0];
                }
                if(indicesAccessor.find("min") != indicesAccessor.end())
                {
                    prim.MinIndex   = indicesAccessor.at("min")[0];
                }
            }

            if(thisPrim.find("material") != thisPrim.end())
            {
                prim.Material   = &gltf->m_materials[thisPrim.at("material")];
            }
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeCameras(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_cameras.reserve(json.size());

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFCamera      camera;
        JSON&       thisCamera      = it.value();

        if(thisCamera["type"] == "perspective")
        {
            JSON&       perspective     = thisCamera["perspective"];
            camera.Type         = GLTFCamera::kPerspective;
            camera.AspectRatio  = 0.0f;
            if(perspective.find("aspectRatio") != perspective.end())
            {
                camera.AspectRatio  = perspective.at("aspectRatio");
            }
            camera.Yfov     = perspective["yfov"];
            camera.zNear    = perspective["znear"];
            camera.zFar     = 0.0f;
            if(perspective.find("zfar") != perspective.end())
            {
                camera.zFar = perspective.at("zfar");
            }
        }
        else
        {
            camera.Type     = GLTFCamera::kOrthographic;
            JSON&   orthographic        = thisCamera["orthographic"];
            camera.xMag     = orthographic["xmag"];
            camera.yMag     = orthographic["ymag"];
            camera.zNear    = orthographic["znear"];
            camera.zFar     = orthographic["zfar"];
            ASSERT(camera.zFar > camera.zNear);
        }

        gltf->m_cameras.push_back(camera);
    }
}

T100VOID T100FileGLTFDecoder::DecodeNodes(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_nodes.resize(json.size());

    T100UINT32      nodeIndex       = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFNode&       node    = gltf->m_nodes[nodeIndex++];
        JSON&       thisNode        = it.value();

        node.Flags          = 0;
        node.Mesh           = T100NULL;
        node.LinearIndex    = -1;

        if(thisNode.find("camera") != thisNode.end())
        {
            node.Camera = &gltf->m_cameras[thisNode.at("camera")];
            node.PointsToCamera = T100TRUE;
        }
        else if(thisNode.find("mesh") != thisNode.end())
        {
            node.Mesh   = &gltf->m_meshes[thisNode.at("mesh")];
        }

        if(thisNode.find("skin") != thisNode.end())
        {
            ASSERT(node.Mesh != T100NULL);
            node.Mesh->Skin     = thisNode.at("skin");
        }

        if(thisNode.find("children") != thisNode.end())
        {
            JSON&   children        = thisNode["children"];
            node.Children.reserve(children.size());
            for(auto& child : children){
                node.Children.push_back(&gltf->m_nodes[child]);
            }
        }

        if(thisNode.find("matrix") != thisNode.end())
        {
            ReadFloats(thisNode["matrix"], node.Matrix);
            node.HasMatrix  = T100TRUE;
        }
        else
        {
            JSON::iterator scale = thisNode.find("scale");
            if(scale != thisNode.end())
            {
                ReadFloats(scale.value(), node.Scale);
            }
            else
            {
                node.Scale[0]       = 1.0f;
                node.Scale[1]       = 1.0f;
                node.Scale[2]       = 1.0f;
            }

            JSON::iterator rotation     = thisNode.find("rotation");
            if(rotation != thisNode.end())
            {
                ReadFloats(rotation.value(), node.Rotation);
            }
            else
            {
                node.Rotation[0]    = 0.0f;
                node.Rotation[1]    = 0.0f;
                node.Rotation[2]    = 0.0f;
                node.Rotation[3]    = 1.0f;
            }

            JSON::iterator translation = thisNode.find("translation");
            if(translation != thisNode.end())
            {
                ReadFloats(translation.value(), node.Translation);
            }
            else
            {
                node.Translation[0]     = 0.0f;
                node.Translation[1]     = 0.0f;
                node.Translation[2]     = 0.0f;
            }
        }
    }
}

T100VOID T100FileGLTFDecoder::DecodeScenes(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_scenes.reserve(json.size());

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        GLTFScene           scene;
        JSON& thisScene     = it.value();

        if(thisScene.find("nodes") != thisScene.end())
        {
            JSON& nodes = thisScene["nodes"];
            scene.Nodes.reserve(nodes.size());
            for(auto& node : nodes){
                scene.Nodes.push_back(&gltf->m_nodes[node]);
            }
        }
        gltf->m_scenes.push_back(scene);
    }
}

T100VOID T100FileGLTFDecoder::DecodeAnimations(JSON& json, T100FileGLTF* gltf)
{
    gltf->m_animations.resize(json.size());
    T100UINT32      animIndex       = 0;

    for(JSON::iterator it = json.begin(); it != json.end(); ++it)
    {
        JSON&   thisAnimation       = it.value();
        GLTFAnimation&  animation   = gltf->m_animations[animIndex++];

        JSON&   samplers    = thisAnimation.at("samplers");
        animation.Samplers.resize(samplers.size());
        T100UINT32      samplerIndex        = 0;

        for(JSON::iterator sampIt = samplers.begin(); sampIt != samplers.end(); ++sampIt)
        {
            JSON&   thisSampler     = sampIt.value();
            GLTFAnimSampler&        sampler     = animation.Samplers[samplerIndex++];
            sampler.Input           = &gltf->m_accessors[thisSampler.at("input")];
            sampler.Output          = &gltf->m_accessors[thisSampler.at("output")];
            sampler.Interpolation   = GLTFAnimSampler::kLinear;

            if(thisSampler.find("interpolation") != thisSampler.end())
            {
                const std::string&    interpolation   = thisSampler.at("interpolation");
                if(interpolation == "LINEAR"){
                    sampler.Interpolation   = GLTFAnimSampler::kLinear;
                }else if(interpolation == "STEP"){
                    sampler.Interpolation   = GLTFAnimSampler::kStep;
                }else if(interpolation == "CATMULLROMSPLINE"){
                    sampler.Interpolation   = GLTFAnimSampler::kCatmullRomSpline;
                }else if(interpolation == "CUBICSPLINE"){
                    sampler.Interpolation   = GLTFAnimSampler::kCubicSpline;
                }
            }
        }

        JSON&   channels    = thisAnimation.at("channels");
        animation.Channels.resize(channels.size());
        T100UINT32      channelIndex        = 0;

        for(JSON::iterator chanIt = channels.begin(); chanIt != channels.end(); ++chanIt)
        {
            JSON&   thisChannel     = chanIt.value();
            GLTFAnimChannel&    channel     = animation.Channels[channelIndex++];
            channel.Sampler = &animation.Samplers[thisChannel.at("sampler")];
            JSON&   thisTarget      = thisChannel.at("target");
            channel.Target  = &gltf->m_nodes[thisTarget.at("node")];
            const std::string&    path    = thisTarget.at("path");
            if(path == "translation"){
                channel.Path    = GLTFAnimChannel::kTranslation;
            }else if(path == "rotation"){
                channel.Path    = GLTFAnimChannel::kRotation;
            }else if(path == "scale"){
                channel.Path    = GLTFAnimChannel::kScale;
            }else if(path == "weights"){
                channel.Path    = GLTFAnimChannel::kWeights;
            }
        }
    }
}

T100D3D12_TEXTURE_ADDRESS_MODE T100FileGLTFDecoder::GLtoD3DTextureAddressMode( T100INT32 glWrapMode )
{
    switch (glWrapMode)
    {
    default: ERROR("Unexpected sampler wrap mode");
    case 33071: return T100D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    case 33648: return T100D3D12_TEXTURE_ADDRESS_MODE_MIRROR;
    case 10497: return T100D3D12_TEXTURE_ADDRESS_MODE_WRAP;
    }
}

T100UINT32 T100FileGLTFDecoder::floatToHalf( T100FLOAT f )
{
    const T100FLOAT kF32toF16 = (1.0 / (1ull << 56)) * (1.0 / (1ull << 56)); // 2^-112
    union { T100FLOAT f; T100UINT32 u; } x;
    x.f = Clamp(f, 0.0f, 1.0f) * kF32toF16;
    return x.u >> 13;
}

T100VOID T100FileGLTFDecoder::ReadFloats( JSON& list, T100FLOAT flt_array[] )
{
    T100UINT32 i = 0;
    for (auto& flt : list)
        flt_array[i++] = flt;
}

T100UINT32 T100FileGLTFDecoder::ReadTextureInfo( JSON& info_json, GLTFTexture* &info, T100FileGLTF* gltf )
{
    info = nullptr;

    if (info_json.find("index") != info_json.end())
        info = &gltf->m_textures[info_json.at("index")];

    if (info_json.find("texCoord") != info_json.end())
        return info_json.at("texCoord");
    else
        return 0;
}

T100VOID T100FileGLTFDecoder::FindAttribute( T100FileGLTF* gltf, GLTFPrimitive& prim, JSON& attributes, GLTFPrimitive::eAttribType type, const std::string& name )
{
    JSON::iterator attrib = attributes.find(name);
    if (attrib != attributes.end())
    {
        prim.AttribMask |= 1 << type;
        prim.Attributes[type] = &gltf->m_accessors[attrib.value()];
    }
    else
    {
        prim.Attributes[type] = T100NULL;
    }
}

T100UINT16 T100FileGLTFDecoder::TypeToEnum( const char type[] )
{
    if (strncmp(type, "VEC", 3) == 0)
        return GLTFAccessor::kVec2 + type[3] - '2';
    else if (strncmp(type, "MAT", 3) == 0)
        return GLTFAccessor::kMat2 + type[3] - '2';
    else
        return GLTFAccessor::kScalar;
}
