#ifndef T1003DEDITORMATERIALMANAGER_H
#define T1003DEDITORMATERIALMANAGER_H

#include <atomic>
#include <wx/wx.h>
#include "T100Common.h"
#include "data/T100Material.h"

class T1003DEditorMaterialManager
{
    public:
        T1003DEditorMaterialManager();
        virtual ~T1003DEditorMaterialManager();

        T100Material*           GetMaterial();

        T100VOID                GetMaterialNames(wxArrayString&);

        T100VOID                GetMaterialList(wxArrayString&, wxArrayInt&, T100WSTRING&, T100UINT&);

    protected:
        std::atomic_int         m_materialCount;
        T100MATERIAL_VECTOR     m_materials;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T1003DEDITORMATERIALMANAGER_H
