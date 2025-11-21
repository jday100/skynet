#ifndef T100TREEITEMDATA_H
#define T100TREEITEMDATA_H

#include <wx/treectrl.h>
#include "T100Common.h"
#include "T1003DEditorUICommon.h"

class T100Entity;
class T1003DMesh;
class T1003DCamera;
class T1003DLight;
class T1003DTexture;

class T100TreeItemData :public wxTreeItemData
{
    public:
        T100TreeItemData();
        virtual ~T100TreeItemData();

        T1003DEDITOR_SCENE_ITEM_TYPE            Type;

        T100VOID                                ShowMenu(wxTreeCtrl*);

        union{
            T100Entity*         Entity;
            T1003DLight*        Light;
            T1003DCamera*       Camera;
            T1003DTexture*      Texture;
            T100VOID*           Pointer         = T100NULL;
        };

    protected:
        T100VOID                ShowEntityCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowMeshCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowCameraCategoryMenu(wxTreeCtrl*);
        T100VOID                ShowLightCategoryMenu(wxTreeCtrl*);

        T100VOID                ShowEntityMenu(wxTreeCtrl*);
        T100VOID                ShowMeshMenu(wxTreeCtrl*);
        T100VOID                ShowCameraMenu(wxTreeCtrl*);
        T100VOID                ShowLightMenu(wxTreeCtrl*);

    private:
};

#endif // T100TREEITEMDATA_H
