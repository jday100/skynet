#ifndef T1003DEDITORSETTINGSSERVE_H
#define T1003DEDITORSETTINGSSERVE_H

#include <wx/arrstr.h>
#include <wx/dynarray.h>

#include "T1003DEditorDescriptionFile.h"
#include "T1003DEditorParameterFile.h"
#include "T1003DEditorShaderData.h"
#include "T1003DEditorParameterReferenceData.h"

class T1003DEditorSettingsServe
{
    public:
        T1003DEditorSettingsServe();
        virtual ~T1003DEditorSettingsServe();

        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&             GetVertexDescriptions();
        T1003DEDITOR_SHADER_PARAMETER_VECTOR&               GetShaderParameters();
        T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&     GetDescriptionReferences();
        T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR&       GetParameterReferences();
        T1003DEDITOR_SHADER_FILE_VECTOR&                    GetVertexShaders();
        T1003DEDITOR_SHADER_FILE_VECTOR&                    GetPixelShaders();
        T1003DEDITOR_SHADER_VECTOR&                         GetShaders();

        T100VOID                        GetDescriptions(wxArrayString&, wxArrayInt&);
        T100VOID                        GetDescriptionReferences(wxArrayString&, wxArrayInt&);
        T100VOID                        GetParameters(wxArrayString&, wxArrayInt&);
        T100VOID                        GetParameterReferences(wxArrayString&, wxArrayInt&);
        T100VOID                        GetVertexShaders(wxArrayString&, wxArrayInt&);
        T100VOID                        GetPixelShaders(wxArrayString&, wxArrayInt&);
        T100VOID                        GetShaders(wxArrayString&, wxArrayInt&);

    protected:
        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR              m_vertexDescriptions;
        T1003DEDITOR_SHADER_PARAMETER_VECTOR                m_shaderParameters;

        T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR      m_descriptionReferences;
        T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR        m_parameterReferences;

        T1003DEDITOR_SHADER_FILE_VECTOR                     m_vertexShaders;
        T1003DEDITOR_SHADER_FILE_VECTOR                     m_pixelShaders;

        T1003DEDITOR_SHADER_VECTOR                          m_shaders;

    private:
};

#endif // T1003DEDITORSETTINGSSERVE_H
