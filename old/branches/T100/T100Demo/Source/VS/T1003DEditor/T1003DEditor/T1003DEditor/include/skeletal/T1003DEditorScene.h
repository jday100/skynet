#ifndef T1003DEDITORSCENE_H
#define T1003DEDITORSCENE_H

#include "entity/T100Line.h"
#include "link/T100Editable.h"
#include "data/T100GameScene.h"
#include "3deditor/T1003DEditorDirection.h"

class T1003DEditorScene : public T100GameScene
{
    friend class T100GameCallback;
    public:
        T1003DEditorScene(T100Game*);
        virtual ~T1003DEditorScene();

        virtual T100VOID            Create();
        virtual T100VOID            Destroy();

        T100VOID                    Reset();

    protected:
        virtual T100VOID            AppendStaticMeshes();
        virtual T100VOID            AppendDynamicsMeshes();

        T1003DObject*               m_selection         = T100NULL;

    private:
        T1003DCamera*               m_cameraPtr         = T100NULL;
        T1003DEditorDirection       m_direction;
        T100Line                    m_horizontal;
        T100Line                    m_vertical;

        T100Line                    m_x;
        T100Line                    m_y;
        T100Line                    m_z;

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITORSCENE_H
