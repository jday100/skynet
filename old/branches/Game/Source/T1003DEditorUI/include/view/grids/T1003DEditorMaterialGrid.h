#ifndef T1003DEDITORMATERIALGRID_H
#define T1003DEDITORMATERIALGRID_H

#include "T1003DEditorGridBase.h"
#include <wx/propgrid/advprops.h>
#include "data/T100Material.h"

class T1003DEditorMaterialGrid : public T1003DEditorGridBase
{
    public:
        T1003DEditorMaterialGrid(wxPropertyGrid*);
        virtual ~T1003DEditorMaterialGrid();

        virtual T100VOID            Update(T100Material*);
        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:
        T100Material*               m_material      = T100NULL;

        wxStringProperty*           m_name;

        wxFloatProperty*            m_diffuseRed;
        wxFloatProperty*            m_diffuseGreen;
        wxFloatProperty*            m_diffuseBlue;
        wxFloatProperty*            m_diffuseAlpha;

        wxFloatProperty*            m_specularRed;
        wxFloatProperty*            m_specularGreen;
        wxFloatProperty*            m_specularBlue;
        wxFloatProperty*            m_specularAlpha;

        wxFloatProperty*            m_ambientRed;
        wxFloatProperty*            m_ambientGreen;
        wxFloatProperty*            m_ambientBlue;
        wxFloatProperty*            m_ambientAlpha;

        wxFloatProperty*            m_emissiveRed;
        wxFloatProperty*            m_emissiveGreen;
        wxFloatProperty*            m_emissiveBlue;
        wxFloatProperty*            m_emissiveAlpha;

        wxFloatProperty*            m_transparentRed;
        wxFloatProperty*            m_transparentGreen;
        wxFloatProperty*            m_transparentBlue;
        wxFloatProperty*            m_transparentAlpha;


    private:
};

#endif // T1003DEDITORMATERIALGRID_H
