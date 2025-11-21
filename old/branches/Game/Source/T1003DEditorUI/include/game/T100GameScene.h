#ifndef T100GAMESCENE_H
#define T100GAMESCENE_H

#include "entity/T100Editable.h"
#include "renderer/data/T100DX12Scene.h"
#include "3deditor/T1003DEditorDirection.h"

class T100GameScene : public T100DX12Scene
{
    friend class T100GameCallback;
    public:
        T100GameScene(T100DX12Renderer*);
        virtual ~T100GameScene();

        T100VOID                            Append(T100Entity*);
        T100VOID                            AppendLight(T100Light*);

        T100VOID                            Rotation(T100Vector3&);

        T100UINT                            Width;
        T100UINT                            Height;

    protected:
        virtual T100VOID                    AppendStaticEntities();
        virtual T100VOID                    AppendDynamicsEntities();

    private:
        T100Entity*                         m_current           = T100NULL;
        T100Editable*                       m_editable          = T100NULL;

        T1003DEditorDirection               m_direction;
        T100Line                            m_horizontal;
        T100Line                            m_vertical;

        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100GAMESCENE_H
