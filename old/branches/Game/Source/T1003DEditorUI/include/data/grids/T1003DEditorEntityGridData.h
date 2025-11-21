#ifndef T1003DEDITORENTITYGRIDDATA_H
#define T1003DEDITORENTITYGRIDDATA_H

#include "T1003DEditorGridDataBase.h"

class T1003DEditorEntityGridData
{
    public:
        T1003DEditorEntityGridData();
        virtual ~T1003DEditorEntityGridData();

        wxPropertyCategory*     m_shader                    = T100NULL;
        wxBoolProperty*         m_shaderInherit             = T100NULL;
        wxEnumProperty*         m_shaderReference           = T100NULL;

        wxStringProperty*       m_descriptions              = T100NULL;
        wxStringProperty*       m_parameters                = T100NULL;
        wxStringProperty*       m_settings                  = T100NULL;

        wxEnumProperty*         m_descriptionsReference     = T100NULL;
        wxEnumProperty*         m_parametersReference       = T100NULL;
        wxEnumProperty*         m_settingsReference         = T100NULL;

        wxUIntProperty*         m_descriptionsAmount        = T100NULL;
        wxUIntProperty*         m_parametersAmount          = T100NULL;

        T1003DEDITOR_GRID_DATA_DESCRIPTION_VECTOR           m_descriptionProperties;
        T1003DEDITOR_GRID_DATA_PARAMETER_VECTOR             m_parameterProperties;

        wxStringProperty*       m_vertexCategory            = T100NULL;
        wxStringProperty*       m_pixelCategory             = T100NULL;

        T1003DEDITOR_GRID_DATA_SHADER                       m_vertexShader;
        T1003DEDITOR_GRID_DATA_SHADER                       m_pixelShader;

    protected:

    private:
};

#endif // T1003DEDITORENTITYGRIDDATA_H
