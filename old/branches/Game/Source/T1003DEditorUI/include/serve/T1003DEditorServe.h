#ifndef T1003DEDITORSERVE_H
#define T1003DEDITORSERVE_H

#include "T1003DEditorDocument.h"
#include "T1003DEditorEntityManager.h"
#include "T1003DEditorCameraManager.h"
#include "T1003DEditorLightManager.h"
#include "T1003DEditorMaterialManager.h"

#include "T1003DEditorSettingsServe.h"

class T1003DEditorServe
{
    public:
        T1003DEditorServe();
        virtual ~T1003DEditorServe();


        T100VOID                        Update(T100Entity*);

        T100BOOL                        Open(T1003DEditorDocument*);

        T1003DEditorDocument*           GetDocument();
        T1003DEditorEntityManager*      GetEntityManager();
        T1003DEditorCameraManager*      GetCameraManager();
        T1003DEditorLightManager*       GetLightManager();
        T1003DEditorMaterialManager*    GetMaterialManager();

        T1003DEditorSettingsServe&      GetSettingsServe();

        T100BOOL                        Append(T100Entity*);
        T100BOOL                        Remove(T100Entity*);

        T100BOOL                        Append(T100Camera*);
        T100BOOL                        Remove(T100Camera*);

        T100BOOL                        AppendLight(T100Light*);
        T100BOOL                        RemoveLight(T100Light*);

        T100BOOL                        Append(T100Material*);
        T100BOOL                        Remove(T100Material*);

    protected:
        T1003DEditorDocument*           m_document          = T100NULL;
        T1003DEditorEntityManager       m_entityManager;
        T1003DEditorCameraManager       m_cameraManager;
        T1003DEditorLightManager        m_lightManager;
        T1003DEditorMaterialManager     m_materialManager;

        T1003DEditorSettingsServe       m_settingsServe;

    private:
        T100VOID                        UpdateEntity(T100Scene&, T100Entity*);
};

#endif // T1003DEDITORSERVE_H
