#ifndef T1003DEDITORENTITYGRID_H
#define T1003DEDITORENTITYGRID_H

#include "T1003DEditorGridBase.h"
#include <wx/propgrid/advprops.h>
#include "entity/T100Entity.h"

class T1003DEditorEntityGrid : public T1003DEditorGridBase
{
    public:
        T1003DEditorEntityGrid(wxPropertyGrid*);
        virtual ~T1003DEditorEntityGrid();

        virtual T100VOID            Update(T100Entity*) = 0;
        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event) = 0;

    protected:
        wxStringProperty*           m_namePtr           = T100NULL;

        wxColourProperty*           m_colourPtr         = T100NULL;

        wxFileProperty*             m_shaderFilePtr     = T100NULL;

        wxBoolProperty*             m_visiblePtr        = T100NULL;

        wxPropertyCategory*         m_positionPtr       = T100NULL;

        wxFloatProperty*            m_positionXPtr      = T100NULL;
        wxFloatProperty*            m_positionYPtr      = T100NULL;
        wxFloatProperty*            m_positionZPtr      = T100NULL;

        wxPropertyCategory*         m_rotationPtr       = T100NULL;

        wxFloatProperty*            m_rotationXPtr      = T100NULL;
        wxFloatProperty*            m_rotationYPtr      = T100NULL;
        wxFloatProperty*            m_rotationZPtr      = T100NULL;

        wxPropertyCategory*         m_scalingPtr        = T100NULL;

        wxFloatProperty*            m_scalingXPtr       = T100NULL;
        wxFloatProperty*            m_scalingYPtr       = T100NULL;
        wxFloatProperty*            m_scalingZPtr       = T100NULL;

        wxBoolProperty*             m_bundlePtr         = T100NULL;
        wxPropertyCategory*         m_categoryPtr       = T100NULL;
        wxPropertyCategory*         m_amountPtr         = T100NULL;
        wxPropertyCategory*         m_spacingPtr        = T100NULL;

        wxIntProperty*              m_amountXPtr        = T100NULL;
        wxIntProperty*              m_amountYPtr        = T100NULL;
        wxIntProperty*              m_amountZPtr        = T100NULL;

        wxFloatProperty*            m_spacingXPtr       = T100NULL;
        wxFloatProperty*            m_spacingYPtr       = T100NULL;
        wxFloatProperty*            m_spacingZPtr       = T100NULL;

        wxEnumProperty*             m_materialPtr       = T100NULL;

        wxPropertyCategory*         m_shader                = T100NULL;
        wxPropertyCategory*         m_vertex                = T100NULL;
        wxPropertyCategory*         m_pixel                 = T100NULL;

        wxBoolProperty*             m_shaderInherit         = T100NULL;
        wxBoolProperty*             m_vertexShaderInherit   = T100NULL;
        wxBoolProperty*             m_pixelShaderInherit    = T100NULL;

        wxFileProperty*             m_vertexShaderFile      = T100NULL;
        wxFileProperty*             m_pixelShaderFile       = T100NULL;

        wxEnumProperty*             m_vertexShaderFileType  = T100NULL;
        wxEnumProperty*             m_pixelShaderFileType   = T100NULL;

        wxStringProperty*           m_vertexShaderEntry     = T100NULL;
        wxStringProperty*           m_vertexShaderTarget    = T100NULL;

        wxStringProperty*           m_pixelShaderEntry      = T100NULL;
        wxStringProperty*           m_pixelShaderTarget     = T100NULL;

    protected:
        T100Entity*                 m_entityPtr         = T100NULL;

        void                        OnEntityPGChanged(wxPropertyGridEvent& event);

        T100VOID                    CreateName();
        T100VOID                    CreateShader();
        T100VOID                    CreateParameters();
        T100VOID                    CreateSettings();
        T100VOID                    CreateVertexShader();
        T100VOID                    CreatePixelShader();

        T100VOID                    CreateEntity();
        T100VOID                    CreateCategories();
        T100VOID                    CreateBundle();
        T100VOID                    SetupBundle(T100BOOL);

    private:
};

#endif // T1003DEDITORENTITYGRID_H
