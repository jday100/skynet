#include "T1003DEditorMaterialManager.h"

#include <wx/wx.h>

T1003DEditorMaterialManager::T1003DEditorMaterialManager()
{
    //ctor
    init();
}

T1003DEditorMaterialManager::~T1003DEditorMaterialManager()
{
    //dtor
    uninit();
}

T100VOID T1003DEditorMaterialManager::init()
{
    m_materialCount     = 0;
}

T100VOID T1003DEditorMaterialManager::uninit()
{

}

T100VOID T1003DEditorMaterialManager::GetMaterialNames(wxArrayString& names)
{
    names.Add(L"");

    for(T100Material* material : m_materials){
        names.Add(material->Name);
    }
}

T100Material* T1003DEditorMaterialManager::GetMaterial()
{
    T100Material*      material       = T100NEW T100Material();
    int     i       = ++m_materialCount;
    material->Name     = wxString::Format(L"Material%u", i);

    m_materials.push_back(material);
    return material;
}

T100VOID T1003DEditorMaterialManager::GetMaterialList(wxArrayString& names, wxArrayInt& values, T100WSTRING& name, T100UINT& value)
{
    T100UINT    index       = 0;
    names.Add(L"");
    values.Add(-1);
    for(T100Material* material : m_materials){
        if(material->Name == name){
            value   = index;
        }
        names.Add(material->Name);
        values.Add(index++);
    }
}
