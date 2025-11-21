#ifndef T100TREEITEMDATA_H
#define T100TREEITEMDATA_H

#include <wx/treectrl.h>
#include "T100Common.h"
#include "T1003DEditorUICommon.h"

class T100Scene;
class T100Entity;
class T100Mesh;
class T100Light;
class T100Camera;
class T100Texture;
class T100Material;

class T100TreeItemData :public wxTreeItemData
{
    public:
        T100TreeItemData();
        virtual ~T100TreeItemData();

        T1003DEDITOR_SCENE_ITEM_TYPE            Type;

        T100VOID                                ShowMenu(wxTreeCtrl*);

        union{
            T100Scene*          Scene;
            T100Entity*         Entity;
            T100Mesh*           Mesh;
            T100Light*          Light;
            T100Camera*         Camera;
            T100Texture*        Texture;
            T100Material*       Material;
            T100VOID*           Pointer         = T100NULL;
        };

    protected:
        T100VOID                ShowEntityCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowMeshCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowCameraCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowLightCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowMaterialCategoryMenu(wxTreeCtrl*);

        T100VOID                ShowEntityMenu(wxTreeCtrl*);
        T100VOID                ShowMeshMenu(wxTreeCtrl*);
        T100VOID                ShowCameraMenu(wxTreeCtrl*);
        T100VOID                ShowLightMenu(wxTreeCtrl*);
        T100VOID                ShowMaterialMenu(wxTreeCtrl*);

    private:
};

#endif // T100TREEITEMDATA_H
