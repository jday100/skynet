#ifndef T1003DEDITORCALLBACK_H
#define T1003DEDITORCALLBACK_H

#include <wx/wx.h>
#include "T100Common.h"

#include <wx/arrstr.h>
#include <wx/dynarray.h>

#include "T1003DEditorDescriptionFile.h"
#include "T1003DEditorParameterFile.h"
#include "T1003DEditorShaderData.h"
#include "T1003DEditorParameterReferenceData.h"

class T100Scene;
class T100Entity;
class T100Mesh;
class T100Camera;
class T100Light;
class T100Material;
class T1003DEditorUIFrame;
class T1003DEditorSkeletal;

class T1003DEditorCallback
{
    public:
        T1003DEditorCallback();
        virtual ~T1003DEditorCallback();

        static T100VOID             Create(T1003DEditorUIFrame*);
        static T100VOID             Destroy();

        static T100VOID             MenuNew();
        static T100VOID             MenuOpen();
        static T100VOID             MenuClose();
        static T100VOID             MenuSave();
        static T100VOID             MenuSaveAs();
        static T100VOID             MenuImport();
        static T100VOID             MenuExport();
        static T100VOID             MenuQuit();

        static T100VOID             MenuUndo();
        static T100VOID             MenuRedo();

        static T100VOID             MenuCut();
        static T100VOID             MenuCopy();
        static T100VOID             MenuPaste();

        static T100VOID             SetMenu(T100WSTRING, T100BOOL);
        static T100VOID             MenuManager(T100BOOL);
        static T100VOID             MenuProperties(T100BOOL);

        static T100VOID             MenuConfig();
        static T100VOID             MenuSettings();

        static T100VOID             MenuAbout();

        static T100VOID             OnKeyDown(T100INT);
        static T100VOID             OnKeyUp(T100INT);

        static T100VOID             Update(T100INT);
        static T100VOID             Update(T100Scene*);
        static T100VOID             Update(T100Entity*);
        static T100VOID             Update(T100Camera*);
        static T100VOID             Update(T100Light*);
        static T100VOID             UpdateMesh(T100Mesh*);
        static T100VOID             Update(T100Material*);
        static T100VOID             UpdateInfo();
        static T100VOID             Clear();

        static T100VOID             UpdateScene(T100Scene*);

        static T100VOID             SetBundle(T100BOOL, T100Entity*);

        static T100VOID             Append();
        static T100VOID             Remove();
        static T100VOID             Append(T100Entity*);
        static T100VOID             Remove(T100Entity*);
        static T100VOID             Move(T100UINT, T100UINT);

        static T100VOID             Position(T100UINT, T100UINT);
        static T100VOID             Rotation(T100INT, T100INT);

        static T100VOID             SetDirty();

        static T100VOID             Cancel();

        static T100VOID             AppendMesh();
        static T100VOID             AppendCamera();
        static T100VOID             AppendLight();
        static T100VOID             AppendMaterial();

        static T100VOID             Append(T100Camera*);

        static T100VOID             SaveConfig();

        static T100VOID             GetMaterialList(wxArrayString&, wxArrayInt&, T100WSTRING&, T100UINT&);
        static T100VOID             GetMaterialNames(wxArrayString&);

        static T100VOID             GetDescriptions(wxArrayString&, wxArrayInt&);
        static T100VOID             GetParameters(wxArrayString&, wxArrayInt&);
        static T100VOID             GetDescriptionReferences(wxArrayString&, wxArrayInt&);
        static T100VOID             GetVertexShaders(wxArrayString&, wxArrayInt&);
        static T100VOID             GetParameterReferences(wxArrayString&, wxArrayInt&);
        static T100VOID             GetPixelShaders(wxArrayString&, wxArrayInt&);
        static T100VOID             GetShaders(wxArrayString&, wxArrayInt&);

        static T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&              GetDescriptions();
        static T100VOID             SaveDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR&);

        static T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&      GetDescriptionReferences();
        static T100VOID             SaveDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR&);

        static T1003DEDITOR_SHADER_PARAMETER_VECTOR&                GetParameters();
        static T100VOID             SaveParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR&);

        static T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR&        GetParameterReferences();
        static T100VOID             SaveParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR&);

        static T1003DEDITOR_SHADER_FILE_VECTOR&                     GetVertexShaders();
        static T100VOID             SaveVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);

        static T1003DEDITOR_SHADER_FILE_VECTOR&                     GetPixelShaders();
        static T100VOID             SavePixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR&);

        static T1003DEDITOR_SHADER_VECTOR&                          GetShaders();
        static T100VOID             SaveShaders(T1003DEDITOR_SHADER_VECTOR&);

    protected:
        static T1003DEditorSkeletal*            m_skeletal;

    private:
};

#endif // T1003DEDITORCALLBACK_H
