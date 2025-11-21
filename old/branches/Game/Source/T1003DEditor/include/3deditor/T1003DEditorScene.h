#ifndef T1003DEDITORSCENE_H
#define T1003DEDITORSCENE_H

#include "T100Line.h"
#include "T100City.h"
#include "T100DX12Scene.h"
#include "T1003DEditorDirection.h"

class T1003DEditorScene : public T100DX12Scene
{
    friend class T1003DEditor;
    public:
        T1003DEditorScene(T100DX12Renderer*);
        virtual ~T1003DEditorScene();

        T100VOID                    AppendStaticEntities();
        T100VOID                    AppendDynamicsEntities();

    protected:
        T1003DEditorDirection       m_direction;

        T100Line                    m_line;
        T100City                    m_city;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T1003DEDITORSCENE_H
