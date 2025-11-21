#ifndef T1003DEDITORSETTINGSSTORE_H
#define T1003DEDITORSETTINGSSTORE_H

#include "T1003DEditorDescriptionFile.h"
#include "T1003DEditorDescriptionReferenceFile.h"
#include "T1003DEditorParameterFile.h"
#include "T1003DEditorParameterReferenceFile.h"
#include "T1003DEditorVertexShaderFile.h"
#include "T1003DEditorPixelShaderFile.h"
#include "T1003DEditorShaderFile.h"

class T1003DEditorSettingsStore
{
    public:
        T1003DEditorSettingsStore();
        virtual ~T1003DEditorSettingsStore();

        T100BOOL            LoadConfigFile();
        T100BOOL            SaveConfigFile();

        T100BOOL            LoadShaders(T1003DEDITOR_SHADER_VECTOR&);
        T100BOOL            SaveShaders(T1003DEDITOR_SHADER_VECTOR&);

        T100BOOL            LoadDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);
        T100BOOL            SaveDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);

        T100BOOL            LoadDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);
        T100BOOL            SaveDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);

        T100BOOL            LoadParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR&);
        T100BOOL            SaveParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR&);

        T100BOOL            LoadParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR&);
        T100BOOL            SaveParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR&);

        T100BOOL            LoadSetting();

        T100BOOL            LoadVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);
        T100BOOL            SaveVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);

        T100BOOL            LoadPixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);
        T100BOOL            SavePixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);

    protected:

    private:
};

#endif // T1003DEDITORSETTINGSSTORE_H
