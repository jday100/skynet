#ifndef T1003DEDITORSERVE_H
#define T1003DEDITORSERVE_H

#include "data/T1003DEditorDocument.h"
#include "serve/T1003DEditorEntityManager.h"
#include "serve/T1003DEditorCameraManager.h"
#include "serve/T1003DEditorLightManager.h"

class T1003DEditorServe
{
    public:
        T1003DEditorServe();
        virtual ~T1003DEditorServe();

        T100BOOL                        Open(T1003DEditorDocument*);
        T1003DEditorDocument*           GetDocument();
        T1003DEditorEntityManager*      GetEntityManager();
        T1003DEditorCameraManager*      GetCameraManager();
        T1003DEditorLightManager*       GetLightManager();

        T100BOOL                        Append(T100Entity*);
        T100BOOL                        Remove(T100Entity*);

        T100BOOL                        Append(T1003DCamera*);
        T100BOOL                        Remove(T1003DCamera*);

        T100BOOL                        Append(T1003DLight*);
        T100BOOL                        Remove(T1003DLight*);

    protected:
        T1003DEditorDocument*           m_document          = T100NULL;
        T1003DEditorEntityManager       m_entityManager;
        T1003DEditorCameraManager       m_cameraManager;
        T1003DEditorLightManager        m_lightManager;

    private:
};

#endif // T1003DEDITORSERVE_H
