#ifndef T100ENTITY_H
#define T100ENTITY_H

#include <vector>

#include "common/T100EntityCommon.h"
#include "common/T100EntityTypes.h"
#include "math/T100Vector3.h"
#include "math/T100Vector3u.h"
#include "math/T100Vector4u.h"
#include "game/file/T100JSON.h"

#define     T100ENTITY_VECTOR           std::vector<T100Entity*>

typedef struct{
    T100BOOL        USED        = T100FALSE;
    struct{
        T100UINT    X           = 1;
        T100UINT    Y           = 1;
        T100UINT    Z           = 1;
    }AMOUNT;
    struct{
        T100FLOAT   X           = 1.0f;
        T100FLOAT   Y           = 1.0f;
        T100FLOAT   Z           = 1.0f;
    }SPACING;
}T100BUNDLE;

class T100DX12Model;
class T100DX12Scene;
class T100DX12Studio;

class T100Entity
{
    friend class T100DX12Scene;
    friend class T100DX12Bundle;
    friend class T100DX12Discrete;
    public:
        T100Entity();
        virtual ~T100Entity();

        T100ENTITY_TYPE             Type;
        T100WSTRING                 Name;

        T100SHADER_SETTING          Shader;

        T100VertexDescriptions      VertexDescriptions;
        T100ShaderParameters        ShaderParameters;

        T100SHADER_FILE             VertexShaderFile;
        T100SHADER_FILE             PixelShaderFile;

        virtual T100VOID            Load(T100DX12Scene*)        = 0;
        virtual T100DX12Model*      Convert(T100DX12Studio*)    = 0;

        T100VOID                    Clear();

        T100VOID                    Transition2D(T100Vector3, T100Vector3&);

        virtual T100VOID            ToJSON(JSON&) = 0;
        virtual T100VOID            FromJSON(JSON&) = 0;

    public:
        T100VOID                    SetVisible(T100BOOL);
        T100BOOL                    GetVisible();

        T100VOID                    SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetPosition(T100Vector3);
        T100Vector3                 GetPosition();

        T100VOID                    SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetRotation(T100Vector3);
        T100Vector3                 GetRotation();

        T100VOID                    SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetScaling(T100Vector3);
        T100Vector3                 GetScaling();

        T100VOID                    SetOrigin(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetOrigin(T100Vector3);
        T100Vector3                 GetOrigin();

        T100VOID                    SetColour(T100UINT, T100UINT, T100UINT, T100UINT);
        T100VOID                    SetColour(T100Vector4u);
        T100Vector4u                GetColour();

        T100VOID                    SetRenderType(T100_RENDER_TYPE);
        T100_RENDER_TYPE            GetRenderType();

        T100VOID                    SetMotionType(T100_MOTION_TYPE);
        T100_MOTION_TYPE            GetMotionType();

        T100VOID                    SetBundle(T100BOOL);
        T100BOOL                    GetBundle();

        T100VOID                    SetBundleAmount(T100UINT, T100UINT, T100UINT);
        T100VOID                    SetBundleAmount(T100Vector3u&);
        T100Vector3u                GetBundleAmount();
        T100VOID                    SetBundleSpacing(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                    SetBundleSpacing(T100Vector3&);
        T100Vector3                 GetBundleSpacing();

        T100VOID                    SetMaterial(T100WSTRING);
        T100WSTRING&                GetMaterial();

    protected:
        T100DX12Model*              m_model             = T100NULL;
        T100_RENDER_TYPE            m_renderType        = T100_RENDER_3D;
        T100_MOTION_TYPE            m_motionType        = T100_MOTION_MOVE;

        T100BOOL                    m_visible           = T100TRUE;
        T100Vector3                 m_position;
        T100Vector3                 m_rotation;
        T100Vector3                 m_scaling;
        T100Vector3                 m_origin;
        T100Vector4u                m_colour;

        T100WSTRING                 m_material;

        T100BUNDLE                  m_bundle;

    protected:
        T100ENTITY_TYPE             ConvertEntityType(T100UINT);

        T100VOID                    EntityToJSON(JSON&);
        T100VOID                    EntityFromJSON(JSON&);

    private:

};



#endif // T100ENTITY_H
