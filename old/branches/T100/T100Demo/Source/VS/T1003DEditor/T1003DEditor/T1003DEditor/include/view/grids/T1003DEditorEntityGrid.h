#ifndef T1003DEDITORENTITYGRID_H
#define T1003DEDITORENTITYGRID_H

#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include "T100Common.h"
#include "link/T100Entity.h"

class T1003DEditorEntityGrid
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

    protected:
        wxPropertyGrid*             m_propertyGridPtr   = T100NULL;
        T100Entity*                 m_entityPtr         = T100NULL;

        void                        OnEntityPGChanged(wxPropertyGridEvent& event);

        T100VOID                    CreateName();
        T100VOID                    CreateEntity();
        T100VOID                    CreateCategories();
        T100VOID                    CreateBundle();
        T100VOID                    SetupBundle(T100BOOL);

    private:
};

#endif // T1003DEDITORENTITYGRID_H
