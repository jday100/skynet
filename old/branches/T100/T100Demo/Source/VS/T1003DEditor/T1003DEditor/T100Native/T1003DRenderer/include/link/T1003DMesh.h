#ifndef T1003DMESH_H
#define T1003DMESH_H

#include "T100Common.h"
#include "T1003DCommon.h"
#include "vector/T100Vector3u.h"
#include "T100Editable.h"

#define     T1003DMESH_VECTOR           std::vector<T1003DMesh*>

class T1003DMesh : public T100Editable
{
    public:
        T1003DMesh(T1003D_RENDER_TYPE = T1003D_RENDER_SPACE, T1003D_MOTION_TYPE = T1003D_MOTION_MOVE);
        virtual ~T1003DMesh();

        virtual T100VOID                    Load() = 0;


        struct T100SHADER_FILE                     PixelShaderFile1;
        struct T100SHADER_FILE                     PixelShaderFile2;
        struct T100SHADER_FILE                     MeshDataFile;
        //

        struct T100SHADER_FILE                     VertexShaderFile;
        struct T100SHADER_FILE                     PixelShaderFile;

        struct T1003D_DATA                         VertexData;

        T100D3D12_INPUT_ELEMENT_DESC*       VertexDescription           = T100NULL;
        T100UINT                            VertexDescriptionLength     = 0;


        T100VOID                            SetBundle(T100BOOL = T100TRUE);
        T100BOOL                            IsBundle();
        T100BUNDLE*                         GetBundlePtr();

        T100VOID                            SetPosition(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetPosition(T100Vector3f&);

        T100VOID                            SetRotation(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetRotation(T100Vector3f&);

        T100VOID                            SetScaling(T100FLOAT, T100FLOAT, T100FLOAT);
        T100VOID                            SetScaling(T100Vector3f&);
        T100Vector3f&                       GetScaling();

        T100VOID                            SetBundleAmount(T100Vector3u&);
        T100Vector3u                        GetBundleAmount();

        T100VOID                            SetBundleSpacing(T100Vector3f&);
        T100Vector3f                        GetBundleSpacing();

        T100VOID                            SetRenderType(T1003D_RENDER_TYPE);
        T1003D_RENDER_TYPE                  GetRenderType();

        T100VOID                            SetMotionType(T1003D_MOTION_TYPE);
        T1003D_MOTION_TYPE                  GetMotionType();

        T100VOID                            SetVisible(T100BOOL = T100TRUE);
        T100BOOL                            IsVisible();

        T1003DMesh*                         GetSelectionPtr();

        T100VOID                            SetAmount(T100UINT);
        T100UINT                            GetAmount();

    protected:
        T100BOOL                            m_visible           = T100TRUE;
        T1003D_RENDER_TYPE                  m_renderType;
        T1003D_MOTION_TYPE                  m_motionType;
        T100BUNDLE                          m_bundle;

        T100Vector3f                        m_scaling;

        T100UINT                            m_amount            = 0;

    private:
};

#endif // T1003DMESH_H
